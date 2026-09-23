#include <stdio.h>

int main() {
    float basic, da, hra, gross;

    printf("Enter the basic pay: ");
    scanf("%f", &basic);

    da = 0.40 * basic;
    hra = 0.20 * basic;

    gross = basic + da + hra;

    printf("Basic Pay: %.2f\n", basic);
    printf("Dearness Allowance (DA): %.2f\n", da);
    printf("House Rent Allowance (HRA): %.2f\n", hra);
    printf("Gross Salary: %.2f\n", gross);

    return 0;
}

