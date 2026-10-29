#include <stdio.h>

int main() {
    char word[100];
    int length = 0;
    int i;
    int isPalindrome = 1;
    
    printf("Enter a word: ");
    scanf("%s", word);

    // 2. Manually find the length of the word without strlen()
    while (word[length] != '\0') {
        length++;
    }

    // 3. Compare characters from both ends moving towards the center
    for (i = 0; i < length / 2; i++) {
        if (word[i] != word[length - 1 - i]) {
            isPalindrome = 0; // Mismatch found, not a palindrome
            break;            // Exit the loop early
        }
    }

    // 4. Output the final result
    if (isPalindrome == 1) {
        printf("%s is a palindrome word.\n", word);
    } else {
        printf("%s is not a palindrome word.\n", word);
    }

    return 0;
}
