#include <stdio.h>

// Function declarations
long long factorialNonRecursive(int n);
long long factorialRecursive(int n);

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Factorial is not defined for negative numbers
    if (n < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } else {
        printf("Factorial of %d (Non-Recursive): %lld\n", n, factorialNonRecursive(n));
        printf("Factorial of %d (Recursive): %lld\n", n, factorialRecursive(n));
    }

    return 0;
}

// Non-Recursive (Iterative) Function
long long factorialNonRecursive(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i; // Multiply numbers from 1 to n
    }
    return fact;
}

// Recursive Function
long long factorialRecursive(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n <= 1) {
        return 1;
    }
    // Recursive case: n! = n * (n-1)!
    return n * factorialRecursive(n - 1);
}

