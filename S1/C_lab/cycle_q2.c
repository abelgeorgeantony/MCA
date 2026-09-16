#include<stdio.h>
double power(double base, int exp) {
    double result = 1.0;
    int is_negative = 0;
    // Handle negative exponents (e.g., 2^-3 = 1 / (2^3))
    if (exp < 0) {
        is_negative = 1;
        exp = -exp; 
    }
    // Multiply the base 'exp' times
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    // If the exponent was negative, invert the final result
    if (is_negative) {
        return 1.0 / result;
    }
    return result;
}

int main() {
    float a, p, r;
    int n, t;
    printf("Enter principal amount: ");
    scanf("%f",&p); 
    printf("Enter rate of interest(P.A): ");
    scanf("%f",&r);
    printf("Enter number of compounding periods per year: ");
    scanf("%d",&n);
    printf("Enter time in years: ");
    scanf("%d",&t);
    a = p * power((1 + ((r/100) / n)), (n * t));
    printf("Compounded interest:\n");
    printf("\tTotal amount: %f\n", a);
    printf("\tInterest only: %f\n", (a - p));
    return 0;
}
