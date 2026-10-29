#include<stdio.h>
int main() {
   int n = 0;
   printf("Enter count of numbers: ");
   scanf("%d", &n);
   
   int nums[n];
   printf("Enter the numbers in random order: ");
   for(int i = 0; i < n; i++)
      scanf("%d", &nums[i]);
   
   int min_idx = 0, temp = 0;
   for (int i = 0; i < n - 1; i++) {
        min_idx = i; // Assume the first element is the smallest

        // Find the actual smallest element in the rest of the array
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[min_idx]) {
                min_idx = j; // Update the index of the minimum element
            }
        }

        // Swap the found minimum element with the first element
        temp = nums[min_idx];
        nums[min_idx] = nums[i];
        nums[i] = temp;
    }
   
   printf("Sorted:\n");
   for(int i = 0; i < n; i++)
      printf("%d\t",nums[i]);
   printf("\n");
   return 0;
}
