#include <stdio.h>
#include <math.h>
int prime(int *n)
{
    int temp = 0;
    for (int i = 2; i <= sqrt(*n); i++)
    {
        if (*n % i == 0)
        {
            temp = 1;
            break;
        }
    }
    return temp;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (prime(&n) == 1)
    {
        printf("NON PRIME\n");
    }
    else
    {
        printf("PRIME\n");
    }
    printf("The worst-case running time of my program is O(sqrt(n))\n");
    return 0;
}