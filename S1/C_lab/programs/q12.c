#include <stdio.h>

int main() {
   int num = 0;
   printf("Enter number:");
   scanf("%d", &num);
   int temp = num, l1 = 0, l2 = 0;
   while(temp != 0) {
      int dig = temp % 10;
      if(dig > l1) {
         l2 = l1;
         l1 = dig;
      }
      else if(dig > l2 && dig != l1) {
         l2 = dig;
      }
      temp = temp / 10;
   }
   printf("Largest: %d\nSecond largest: %d\n", l1, l2);
   return 0;
}
