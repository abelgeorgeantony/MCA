#include <stdio.h>
#include <math.h>
// add the -lm flag at the end of your compilation command to link the math library

int main() {
    int low, high, i, temp1, temp2, remainder, n = 0;
    double result = 0.0;

    printf("Enter two intervals (lower and upper bounds): ");
    scanf("%d %d", &low, &high);

    // Swap numbers if the lower bound is greater than the upper bound
    if (low > high) {
        int temp = low;
        low = high;
        high = temp;
    }

    printf("Armstrong numbers between %d and %d are: \n", low, high);

    // Iterate through each number in the interval
    for (i = low; i <= high; ++i) {
        temp2 = i;
        temp1 = i;

        // Step 1: Count the number of digits (order)
        while (temp1 != 0) {
            temp1 /= 10;
            ++n;
        }

        // Step 2: Calculate the sum of the power of individual digits
        while (temp2 != 0) {
            remainder = temp2 % 10;
            // Use round() to prevent floating-point inaccuracies from pow()
            result += round(pow(remainder, n));
            temp2 /= 10;
        }

        // Step 3: Check if the sum equals the original number
        if ((int)result == i) {
            printf("%d ", i);
        }

        // Reset tracking variables for the next number iteration
        n = 0;
        result = 0.0;
    }

    printf("\n");
    return 0;
}

