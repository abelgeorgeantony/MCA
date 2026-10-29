#include <stdio.h>

void convertBase(int num, int base) {
    char digits[] = "0123456789ABCDEF";
    char result[32];
    int i = 0;

    // Handle 0 explicitly
    if (num == 0) {
        printf("0\n");
        return;
    }

    // Process the number and store remainders in the array
    while (num > 0) {
        result[i] = digits[num % base]; 
        num = num / base;               
        i++;
    }

    // Print the result array in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", result[j]);
    }
    printf("\n");
}

int main() {
    int decimalNum, targetBase;

    printf("Enter a positive decimal number: ");
    scanf("%d", &decimalNum);

    printf("Enter the target base (2 for Binary, 8 for Octal, 16 for Hex): ");
    scanf("%d", &targetBase);

    if (targetBase < 2 || targetBase > 16) {
        printf("Please enter a base between 2 and 16.\n");
        return 1;
    }

    printf("Decimal %d in base %d is: ", decimalNum, targetBase);
    convertBase(decimalNum, targetBase);

    return 0;
}
