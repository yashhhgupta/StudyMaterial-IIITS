#include<stdio.h>

int main()
{
    int a;
    printf("enter a number\n");
    scanf("%d",&a);

    if (a>0)
    {
        printf("given number is positive\n");
    }

    else if(a<0)
    {
        printf("given number is negative\n");
    }
    else
    {
        printf("given number is zero\n");
    }
    
    
    return 0;
}
