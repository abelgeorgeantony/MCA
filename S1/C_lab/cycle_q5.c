#include <stdio.h>

int main() {
    int a, limit = 10;
    printf("Enter the number for which multiplication table should be printed: ");
    scanf("%d", &a);
    printf("\nMULTIPLICATION TABLE OF %d TILL %d\n", a, limit);
    for(int i = 1; i <= limit; i++) {
        printf("%d X %d = %d\n", a, i, (a*i));
    }
    return 0;
}
