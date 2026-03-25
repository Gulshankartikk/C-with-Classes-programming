#include <stdio.h>
#include <string.h>

int braces(char* A) {
    char s[1000];   // stack array
    int top = -1;
    
    int count, i = 0, n = strlen(A);
    
    while (i < n)
    {
        if (A[i] != ')')
            s[++top] = A[i];   // push
        else
        {
            count = 0;
            while (top >= 0 && s[top] != '(')
            {
                count++;
                top--;   // pop
            }
           
            if (count < 3)
                return 1;
           
            if (top >= 0)
                top--;   // pop '('
           
            s[++top] = 'a'; 
        }
        i++;
    }
    return 0;
}

int main() {
    char A[1000];

    printf("Enter expression: ");
    fgets(A, sizeof(A), stdin);   // safe input

    int result = braces(A);

    if (result == 1)
        printf("Redundant braces found\n");
    else
        printf("No redundant braces\n");

    return 0;
}