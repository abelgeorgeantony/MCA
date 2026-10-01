#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0; // 0 and 1 are not prime numbers
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Number is divisible, so it is not prime
        }
    }
    return 1; // Number is prime
}

int main() {
    int n, flag = 0;

    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Check pairs from 2 up to n/2
    for (int i = 2; i <= n / 2; i++) {
        // Check if both i and (n - i) are prime
        if (isPrime(i)) {
            if (isPrime(n - i)) {
                printf("%d = %d + %d\n", n, i, n - i);
                flag = 1; // A valid pair was found
            }
        }
    }

    if (flag == 0) {
        printf("%d cannot be expressed as the sum of two prime numbers.\n", n);
    }

    return 0;
}

