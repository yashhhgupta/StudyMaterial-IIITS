#include <stdio.h>

void factorial(int *number, int *x)
{
    if (*number == 1 || *number == 0)
    {
        return;
    }

    else
    {
        *x =*x * *number;
        *number = *number - 1;
        factorial(number,x);
    }
}

void main()
{
    int num;
    int x=1;
    printf("enter a number you want factorial of:");
    scanf("%d", &num);
    factorial(&num,&x);
    printf("the factorial is %d", x);
}