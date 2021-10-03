#include <stdio.h>
int main()
{
    int a;
    printf("enter a number\n");
    scanf("%d",&a);
    switch (a%55==0)
    {
    case 1:
        printf("divisible");
        break;
    
    default:
        printf("not divisible");
        break;
    }
}