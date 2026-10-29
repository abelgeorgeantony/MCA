#include <stdio.h>

int findLargest(int arr[], int size) {
    int max = arr[0]; // Assume the first element is the largest

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i]; // Update max if a larger element is found
        }
    }
    return max;
}

int main() {
    int n = 0;

    printf("Enter count of numbers: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int nums[n];

    printf("Enter the numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int largest = findLargest(nums, n);

    printf("The largest number is: %d\n", largest);

    return 0;
}
