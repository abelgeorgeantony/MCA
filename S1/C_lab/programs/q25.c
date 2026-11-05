#include<stdio.h>

void swap(int *, int *);

int main() {
	int n1 = 0, n2 = 0;
	printf("Enter 2 number:\n");
	scanf("%d%d", &n1, &n2);
	printf("\nBefore swap:\nn1 = %d\nn2 = %d\n", n1, n2);
	swap(&n1, &n2);
	printf("After swap:\nn1 = %d\nn2 = %d\n", n1, n2);
	return 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
