#include<stdio.h>
#include<stdlib.h>

int main() {
   FILE *fp;
   char *stack = NULL;
   int ch = 0;
   int top = -1, flag = 0;
   fp = fopen("q30_input.txt", "r");
   if(fp == NULL) {
   	printf("File couldn't be opened!\n");
   	return 1;
   }
   while((ch = fgetc(fp)) != EOF) {
   	if(ch == '(' || ch == '{' || ch == '[')
	{
	    top++;
            // Expand stack by 1 byte
            char *temp = realloc(stack, (top + 1) * sizeof(char));
            if (temp == NULL) {
                printf("Memory allocation failed!\n");
                free(stack);
                fclose(fp);
                return 1;
            }
            stack = temp;
            stack[top] = (char)ch;
	}
	else if(ch == ')' || ch == '}' || ch == ']')
	{
	    if(top == -1) {
		flag = 1;
		break;
	    }
	    if((ch == ')' && stack[top] == '(') ||
	       (ch == '}' && stack[top] == '{') ||
	       (ch == ']' && stack[top] == '[')
	      ) {
		top--;
		if (top == -1) {
                    // Stack is empty, free memory completely
                    free(stack);
                    stack = NULL;
                } else {
                    // Shrink stack by 1 byte
                    char *temp = realloc(stack, (top + 1) * sizeof(char));
                    if (temp != NULL) {
                        stack = temp;
                    }
                }
	    }
	    else {
		flag = 1;
		break;
	    }
   	}
   }
   free(stack);
   fclose(fp);
   
   if(flag == 0 && top == -1)
	printf("All brackets are properly matched.\n");
   else
	printf("Mismatch of brackets found.\n");
   return 0;
}
