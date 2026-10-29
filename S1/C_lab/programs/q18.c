#include <stdio.h>

int main() {
    int n, i, j;
    int max_len = 0;
    int longest_idx = 0;

    printf("Enter the number of strings: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    
    char arr[n][100];

    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        scanf(" %99[^\n]", arr[i]);
    }

    for (i = 0; i < n; i++) {
        int len = 0;
        for (j = 0; arr[i][j] != '\0'; j++) {
            len++;
        }

        if (len > max_len) {
            max_len = len;
            longest_idx = i;
        }
    }

    printf("\nThe lengthiest string is: \"%s\"\n", arr[longest_idx]);
    printf("Length: %d characters\n", max_len);

    return 0;
}
