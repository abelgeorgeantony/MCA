#include <stdio.h>

int main() {
    int integerVar;
    float floatVar;
    double doubleVar;
    char charVar1, charVar2;
    
    
    printf("Enter an integer: ");
    scanf("%d", &integerVar);

    printf("Enter a float: ");
    scanf("%f", &floatVar);

    printf("Enter a double: ");
    scanf("%lf", &doubleVar);

    printf("Enter a single character: ");
    scanf(" %c", &charVar1);
    
    //THE FOLLOWING 2 LINES ARE FOR FLUSHING THE NEWLINE OR SUCH CHARACTERS FROM THE INPUT BUFFER SO THAT THE GETCHAR() CAN WORK WITHOUT ERRORS
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Enter a character using getchar(): ");
    charVar2 = getchar();
    
    
    printf("\n--- Displaying Outputs ---\n");
    printf("Integer value entered: %d\n", integerVar);
    printf("Float value entered:   %f (or rounded to 2 decimals: %.2f)\n", floatVar, floatVar);
    printf("Double value entered:  %lf\n", doubleVar);
    printf("Character entered:     %c\n", charVar1);

    printf("The character you entered displayed via putchar(): ");
    putchar(charVar2);
    putchar('\n');

    printf("\n==================================================\n");
    return 0;
}

