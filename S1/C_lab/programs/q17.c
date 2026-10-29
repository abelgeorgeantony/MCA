#include <stdio.h>

int main() {
    char word[100];
    int i = 0;
    int spacecount = 0, vowelcount = 0, consonantcount = 0;

    printf("Enter a string: ");
    scanf("%99[^\n]", word);

    while (word[i] != '\0') {
        char ch = word[i];

        if (ch == ' ') {
            spacecount++;
        }
        else if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                 ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowelcount++;
        }
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            consonantcount++;
        }

        i++;
    }

    printf("Vowels: %d\n", vowelcount);
    printf("Consonants: %d\n", consonantcount);
    printf("Spaces: %d\n", spacecount);

    return 0;
}
