#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
int main()
{
    int m, n;
    printf("Enter order of matrix to be generated in format of m n\n");
    scanf("%d %d", &m, &n);
    printf("Enter x and y values for generating multiplication table\n");
    int x, y;
    scanf("%d %d", &x, &y);
    int array[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] = (i + x) * (j + y - n + 1);
        }
    }
    printf("The following is the multiplication table\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\n", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}