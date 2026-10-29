#include<stdio.h>
int main() {
   int n = 0;
   printf("Enter count of numbers: ");
   scanf("%d", &n);
   
   int nums[n];
   printf("Enter the numbers: ");
   for(int i = 0; i < n; i++)
      scanf("%d", &nums[i]);
   
   int sum = 0;
   for(int i = 0; i < n; i++)
      sum = sum + nums[i];
   int avg = sum / n;
   
   printf("Average = %d\n", avg);
   return 0;
}
