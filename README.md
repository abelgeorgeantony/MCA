# MCA

Lab work from my Master of Computer Applications at UCC, Aluva, organised by semester and subject. The repo also holds the script I use to get a usable dev environment on the lab machines.

## Setup

Paste this on every login. It builds the environment on the first run and just re-installs the launcher on later runs, then drops you into it.

```bash
wget -qO- https://raw.githubusercontent.com/abelgeorgeantony/MCA/main/setup_alpine_env.sh | bash && ~/.local/bin/alpine-proot
```

No `wget` on the machine? Use curl:

```bash
curl -fsSL https://raw.githubusercontent.com/abelgeorgeantony/MCA/main/setup_alpine_env.sh | bash && ~/.local/bin/alpine-proot
```

The full path is needed because `~/.local/bin` is only added to `PATH` for new shells.

## Every other terminal tab

```bash
alpine-proot
```

## Get the code

Inside the environment, your home directory is mounted at `/workspace`.

```bash
git clone https://github.com/abelgeorgeantony/MCA.git && cd MCA
```

## What the script does

- Downloads a static [PRoot](https://proot.gitlab.io/proot/) and the latest Alpine minirootfs into `~/.local_env`. No root needed.
- Installs `bash gdb git curl neovim nano openssh-client ca-certificates less tmux tree` inside it.
- Writes a git config and shell prompt inside the environment.
- Installs the `alpine-proot` command in `~/.local/bin` and adds that directory to `PATH` in `~/.bashrc`.

It only sets things up and never enters the environment on its own. The one-liner above does that for you.

## If something breaks

A half-finished first run is cleaned up automatically on the next run. For a full reset:

```bash
rm -rf ~/.local_env
```

Then run the setup command again.

## Layout

```
MCA
├── setup_alpine_env.sh
└── S1
    ├── C_lab
    │   ├── Cycle 1-3 2026.docx   # lab sheets
    │   └── programs/             # q1.c ... q12.c
    └── DBMS_lab
        ├── DBMS_Lab cycle *.docx # lab sheets
        └── session_logs/         # MySQL session logs, by cycle
```


## Editing the script

The settings are at the top of `setup_alpine_env.sh`: git name and email, editor, Alpine branch and the package list. Change the git identity if you fork this.
