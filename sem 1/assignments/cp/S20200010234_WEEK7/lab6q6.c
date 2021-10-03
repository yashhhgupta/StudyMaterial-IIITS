#include <stdio.h>

int main()
{   int number,digit;
    printf("enter a number\n");
    scanf("%d", &number);
    int a=0,b=1;
    printf("fibonacci series=%d %d ", a,b);
    
    for (int i = 0; i < number-2; i++)
    {
        digit=a+b;
        printf("%d ",digit);
        a=b;
        b=digit;
    }
    
    return 0;
}