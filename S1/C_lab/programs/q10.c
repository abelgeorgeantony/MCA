#include <stdio.h>

int main() {
   int range = 0;
   double sum = 0;
   unsigned long fact = 1;
   
   printf("Enter range: ");
   scanf("%d", &range);
   
   for(int i = 1; i <= range; i++){
      fact *= i;
      sum = sum + ((double)i / fact);
   }
   
   printf("Sum = %f\n", sum);
   return 0;
}

