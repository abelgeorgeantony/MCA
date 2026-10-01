#include <stdio.h>

int main() {
    int base, exponent;
    long long result = 1;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent (positive integer): ");
    scanf("%d", &exponent);

    for (int i = 1; i <= exponent; i++) {
        result *= base;
    }

    printf("%d^%d = %lld\n", base, exponent, result);

    return 0;
}

