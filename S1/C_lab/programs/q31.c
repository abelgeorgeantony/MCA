#include <stdio.h>
int main() {
    FILE *fp, *fe, *fo;
    int n, i, num;
    fp = fopen("q31_numbers.txt", "w");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the numbers:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &num);
        fprintf(fp, "%d ", num);
    }
    fclose(fp);
    fp = fopen("q31_numbers.txt", "r");
    fe = fopen("q31_even.txt", "w");
    fo = fopen("q31_odd.txt", "w");
    while(fscanf(fp, "%d", &num) != EOF)
    {
        if(num % 2 == 0)
            fprintf(fe, "%d ", num);
        else
            fprintf(fo, "%d ", num);
    }
    fclose(fp);
    fclose(fe);
    fclose(fo);
    printf("\nEven numbers stored in even.txt\n");
    printf("\nOdd numbers stored in odd.txt\n");
    return 0;
}
