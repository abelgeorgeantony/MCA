#!/usr/bin/env bash
#
# MCA lab dev environment bootstrap.
# Run on every login:  wget -qO- https://raw.githubusercontent.com/abelgeorgeantony/MCA/main/setup_env.sh | bash
#
# This script only PROVISIONS. To enter the environment, run: alpine-proot

set -euo pipefail

# ─────────── your settings ───────────
CMD_NAME="alpine-proot"     # the command you'll type to enter the env
GIT_NAME="Abel George Antony"
GIT_EMAIL="abelgeorgeantony@gmail.com"
GIT_EDITOR="vim"
ALPINE_BRANCH="v3.23"

# Essential packages (output shown)
ESSENTIAL_PKGS="bash gdb git curl neovim nano openssh-client ca-certificates less tmux tree musl-locales"

# Developer bloat (output hidden, installed in background)
BLOAT_PKGS="htop strace ltrace ripgrep fd bat jq fzf eza python3 py3-pip build-base cmake nodejs npm zsh"
# ─────────────────────────────────────

DEV_DIR="$HOME/.local_env"
ROOTFS_DIR="$DEV_DIR/rootfs"
BIN_DIR="$HOME/.local/bin"
STAMP="$DEV_DIR/.provisioned"
PROOT_URL="https://proot.gitlab.io/proot/bin/proot"
ARCH="$(uname -m)"
MIRROR="https://dl-cdn.alpinelinux.org/alpine/$ALPINE_BRANCH/releases/$ARCH"

say() { printf '  %s\n' "$*"; }

# Download to a file, wget or curl, whichever exists.
fetch() {
    if   command -v wget >/dev/null 2>&1; then wget -qO "$2" "$1"
    elif command -v curl >/dev/null 2>&1; then curl -fsSL -o "$2" "$1"
    else echo "Neither wget nor curl found. Can't bootstrap." >&2; exit 1
    fi
}

# Download to stdout.
fetch_out() {
    if   command -v wget >/dev/null 2>&1; then wget -qO- "$1"
    elif command -v curl >/dev/null 2>&1; then curl -fsSL "$1"
    else echo "Neither wget nor curl found. Can't bootstrap." >&2; exit 1
    fi
}

# Install the launcher + PATH hook. Done on every run, so it survives a home wipe.
install_launcher() {
    mkdir -p "$BIN_DIR"

    cat > "$BIN_DIR/$CMD_NAME" <<'LAUNCHER'
#!/bin/sh
# Enter the MCA dev environment.
DEV_DIR="$HOME/.local_env"
ROOTFS_DIR="$DEV_DIR/rootfs"

if [ ! -f "$DEV_DIR/.provisioned" ]; then
    echo "Dev environment isn't set up. Run the setup script first." >&2
    exit 1
fi

# proot's seccomp acceleration breaks on some kernels; fall back quietly.
"$DEV_DIR/proot" -S "$ROOTFS_DIR" /bin/true >/dev/null 2>&1 || export PROOT_NO_SECCOMP=1

# Mount SSH keys if they exist for seamless git operations
SSH_MOUNT=""
if [ -d "$HOME/.ssh" ]; then
    SSH_MOUNT="-b $HOME/.ssh:/root/.ssh"
fi

exec "$DEV_DIR/proot" \
    -S "$ROOTFS_DIR" \
    -b "$HOME:/workspace" \
    $SSH_MOUNT \
    -w /workspace \
    /usr/bin/env HOME=/root TERM="${TERM:-xterm-256color}" /bin/bash
LAUNCHER
    chmod +x "$BIN_DIR/$CMD_NAME"

    local marker="# >>> mca lab env >>>"
    if ! grep -qF "$marker" "$HOME/.bashrc" 2>/dev/null; then
        {
            echo ""
            echo "$marker"
            echo 'export PATH="$HOME/.local/bin:$PATH"'
            echo "# <<< mca lab env <<<"
        } >> "$HOME/.bashrc"
    fi
}

# ─────────── already built? ───────────
if [ -f "$STAMP" ]; then
    install_launcher
    echo "Dev environment already present."
    say "Enter it with:  $BIN_DIR/$CMD_NAME   (or just '$CMD_NAME' in a new tab)"
    say "(Delete $STAMP to force a rebuild if you updated package lists)"
    exit 0
fi

echo "Bootstrapping dev environment in $DEV_DIR ..."

# Any leftovers mean a previous run died halfway. Start clean.
rm -rf "$ROOTFS_DIR"
mkdir -p "$DEV_DIR"
cd "$DEV_DIR"

# ─────────── 1. static proot ───────────
if [ ! -x "$DEV_DIR/proot" ]; then
    say "Downloading PRoot ..."
    fetch "$PROOT_URL" "$DEV_DIR/proot.part"
    [ -s "$DEV_DIR/proot.part" ] || { echo "PRoot download failed or empty." >&2; exit 1; }
    chmod +x "$DEV_DIR/proot.part"
    mv "$DEV_DIR/proot.part" "$DEV_DIR/proot"
fi

# ─────────── 2. Alpine rootfs ───────────
say "Looking up latest Alpine $ALPINE_BRANCH minirootfs ..."
TARBALL="$(fetch_out "$MIRROR/latest-releases.yaml" \
           | awk '/file: alpine-minirootfs/ {print $2; exit}')"
[ -n "$TARBALL" ] || { echo "Couldn't work out the minirootfs filename from the mirror." >&2; exit 1; }

say "Downloading $TARBALL ..."
fetch "$MIRROR/$TARBALL" "$DEV_DIR/alpine.tar.gz"

say "Extracting ..."
BUILD_DIR="$(mktemp -d "$DEV_DIR/.build.XXXXXX")"
tar -xzf "$DEV_DIR/alpine.tar.gz" -C "$BUILD_DIR"
rm -f "$DEV_DIR/alpine.tar.gz"
mv "$BUILD_DIR" "$ROOTFS_DIR"

[ -r /etc/resolv.conf ] && cp /etc/resolv.conf "$ROOTFS_DIR/etc/resolv.conf"

# ─────────── 3. packages ───────────
"$DEV_DIR/proot" -S "$ROOTFS_DIR" /bin/true >/dev/null 2>&1 || export PROOT_NO_SECCOMP=1

say "Installing essential dev tools ..."
"$DEV_DIR/proot" -S "$ROOTFS_DIR" -w /root /bin/sh -c "
    set -e
    apk update
    apk add --no-cache $ESSENTIAL_PKGS
"

say "Downloading bloat ..."
"$DEV_DIR/proot" -S "$ROOTFS_DIR" -w /root /bin/sh -c "apk add --no-cache $BLOAT_PKGS > /tmp/bloat.log 2>&1" &
APK_PID=$!

while kill -0 "$APK_PID" 2>/dev/null; do
    printf '.'
    sleep 0.5
done

wait "$APK_PID"
APK_EXIT=$?
printf '\n'

if [ $APK_EXIT -ne 0 ]; then
    echo "Bloat installation failed. Last few lines of the log:" >&2
    tail -n 20 "$ROOTFS_DIR/tmp/bloat.log" >&2
    exit 1
fi

# ─────────── 4. config inside the env ───────────
say "Writing git identity and shell config ..."

cat > "$ROOTFS_DIR/root/.gitconfig" <<GITCONFIG
[user]
	name = $GIT_NAME
	email = $GIT_EMAIL
[core]
	editor = $GIT_EDITOR
[init]
	defaultBranch = main
[pull]
	rebase = false
[color]
	ui = auto
[alias]
	st = status -sb
	lg = log --oneline --graph --decorate -20
	co = checkout
	cm = commit -m
GITCONFIG

cat > "$ROOTFS_DIR/root/.bashrc" <<'GUESTRC'
# Fix UTF-8 issues inherent to Alpine/musl
export LANG=C.UTF-8
export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
export PS1='\[\033[01;32m\]alpine-env\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
alias ll='ls -lah'

# Modern replacements (if installed via bloat list)
if command -v eza >/dev/null 2>&1; then alias ls='eza'; alias ll='eza -lah'; fi
if command -v bat >/dev/null 2>&1; then alias cat='bat'; fi

# fzf shell integration
if command -v fzf >/dev/null 2>&1; then
    source /usr/share/fzf/key-bindings.bash 2>/dev/null || true
    source /usr/share/fzf/completion.bash 2>/dev/null || true
fi
GUESTRC

# ─────────── 5. done ───────────
touch "$STAMP"
install_launcher

echo ""
echo "Environment ready."
say "Enter it with:  $BIN_DIR/$CMD_NAME"
say "New terminal tabs can just run:  $CMD_NAME"
say "Your alpine-proot home is mounted at /workspace inside."
