#include <stdio.h>

int main()
{
    int num;
    long a = 1;
    printf("enter a number you want factorial of:");
    scanf("%d", &num);
    for (int i = 1; i <=num; i++)
    {
        a = a * i;
    }

    printf("%d", a);

    return 0;
}
