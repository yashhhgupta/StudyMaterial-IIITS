#include <stdio.h>
int main()
{
    int i, num, count, max;
    printf("\nPlease Enter the max Value\n");
    scanf("%d", &max);
    num = 1;
    printf("Prime nums Between 1 and %d are:\n", max);
    while (num <= max)
    {
        count = 0;
        i = 2;
        while (i <= num / 2)
        {
            if (num % i == 0)
            {
                count++;
                break;
            }
            i++;
        }
        if (count == 0 && num != 1)
        {
            printf(" %d ", num);
        }
        num++;
    }
    return 0;
}