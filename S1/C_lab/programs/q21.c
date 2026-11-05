#include <stdio.h>

// Function declaration
void reverseString(char str[], int start, int end);

int main() {
    char str[100];
    int length = 0;

    printf("Enter a string: ");
    // Reads a line of text including spaces until Enter is pressed
    scanf("%[^\n]", str);

    // Manually find the length of the string without <string.h>
    while (str[length] != '\0') {
        length++;
    }

    // Pass the string, start index (0), and end index (length - 1)
    reverseString(str, 0, length - 1);

    printf("Reversed string: %s\n", str);

    return 0;
}

// Recursive function to reverse the string in-place
void reverseString(char str[], int start, int end) {
    // Base case: if start index meets or crosses end index, we are done
    if (start >= end) {
        return;
    }

    // Swap the characters at start and end indices
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive case: move indices inward and call again
    reverseString(str, start + 1, end - 1);
}

