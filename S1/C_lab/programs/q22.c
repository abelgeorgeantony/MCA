#include <stdio.h>

// Function declarations
int stringLength(char str[]);
void stringCopy(char target[], char source[]);
void stringConcat(char target[], char source[]);
int stringCompare(char str1[], char str2[]);

int main() {
    char str1[100], str2[100], target[200];

    // Input strings from user
    printf("Enter first string: ");
    scanf("%[^\n]", str1);
    
    // Clear input buffer before reading the next string
    while (getchar() != '\n'); 

    printf("Enter second string: ");
    scanf("%[^\n]", str2);

    // 1. Length Operation
    printf("\n1. Length of First String: %d\n", stringLength(str1));
    printf("   Length of Second String: %d\n", stringLength(str2));

    // 2. Copy Operation
    stringCopy(target, str1);
    printf("2. Copied First String to target: \"%s\"\n", target);

    // 3. Comparison Operation
    int compResult = stringCompare(str1, str2);
    if (compResult == 0) {
        printf("3. Comparison: Strings are equal.\n");
    } else if (compResult > 0) {
        printf("3. Comparison: First string is lexicographically larger.\n");
    } else {
        printf("3. Comparison: Second string is lexicographically larger.\n");
    }

    // 4. Concatenation Operation
    stringConcat(str1, str2);
    printf("4. Concatenated String (First + Second): \"%s\"\n", str1);

    return 0;
}

// i) Find length of a string
int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// ii) Copy source string into target string
void stringCopy(char target[], char source[]) {
    int i = 0;
    while (source[i] != '\0') {
        target[i] = source[i];
        i++;
    }
    target[i] = '\0'; // Don't forget the null terminator
}

// iii) Append source string to the end of target string
void stringConcat(char target[], char source[]) {
    int targetLen = stringLength(target);
    int i = 0;
    
    // Start copying source elements from where target ended
    while (source[i] != '\0') {
        target[targetLen + i] = source[i];
        i++;
    }
    target[targetLen + i] = '\0'; // Add null terminator to the end
}

// iv) Compare two strings (Returns 0 if equal)
int stringCompare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i]; // Return difference of mismatched characters
        }
        i++;
    }
    return str1[i] - str2[i]; // Return difference if one string is shorter
}

