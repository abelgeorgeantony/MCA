#include <stdio.h>

int main() {
    int n1, n2, a, b, temp, gcd, lcm;
    
    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);

    a = n1;
    b = n2;

    // Standard Euclidean Algorithm loop to find GCD
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;

    // Calculate LCM using the formula: (n1 * n2) / GCD
    lcm = (n1 * n2) / gcd;

    printf("GCD = %d\n", gcd);
    printf("LCM = %d\n", lcm);

    return 0;
}

