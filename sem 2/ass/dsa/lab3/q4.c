#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
int checkMagic(int *p, int n)
{
    int diag = 0, andiag = 0, line = 0, aline = 0;
    for (int i = 0; i < n; i++)
    {
        diag += *(p + i * n + i);
        andiag += *(p + i * n + n - 1 - i);
        line += *(p + i);
        aline += *(p + i * n);
    }
    if (diag != andiag)
        return 0;
    if (line != diag)
        return 0;
    for (int i = 1; i < n; i++)
    {
        int ref = 0;
        for (int j = 0; j < n; j++)
        {
            ref += *(p + i * n + j);
        }
        if (ref != line)
            return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int ref = 0;
        for (int j = 0; j < n; j++)
        {
            ref += *(p + j * n + i);
        }
        if (ref != aline)
            return 0;
    }
    return 1;
}
int main()
{
    //question 4a
    int n;
    printf("Enter order of magic square\n");
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter the elements of the square matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int *p = &arr[0][0];
    int ans = checkMagic(p, n);
    if (ans)
        printf("The given matrix is a Magic Square\n");
    else
        printf("The given matrix is not a Magic Square\n");
        
    //    Question 4 b
    clock_t begin = clock();
    printf("Enter the size of array for playing the game\n");
    int e;
    scanf("%d", &e);
    int d[e][e];
    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < e; j++)
        {
            d[i][j] = 0;
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }
    int alters = 0;
    int shard = 1;
    int time_spent;
    while (shard == 1)
    {
        printf("Enter the number beside it for performing the operation\n");
        printf("Enter data :-1\nAlter previous entry :-2\nNo more entries: 3\n");
        int o;
        scanf("%d", &o);
        int g;
        int q, z;
        if (o == 1)
        {
        here:
            printf("Enter the row and column where you want to enter the data(index starts from 1)\n");
            scanf("%d %d", &q, &z);
            printf("Enter the number\n");
            scanf("%d", &d[q - 1][z - 1]);
            alters++;
            printf("Do you want to confirm your entry\nEnter 1 for yes\n 0 for no\n");
            scanf("%d", &g);
            if (g == '0')
                goto here;
        }
        else if (o == 2)
        {
        there:
            printf("Enter the row and column where you want to alter the data(index starts from 1)\n");
            scanf("%d %d", &q, &z);
            printf("Enter the number\n");
            scanf("%d", &d[q - 1][z - 1]);
            alters++;
            printf("Do you want to confirm your entry\nEnter 1 for yes\n 0 for no \n");
            scanf("%d", &g);
            if (g == '0')
                goto there;
        }
        else if (o == 3)
        {
            shard = 0;
            clock_t end = clock();
            time_spent = (int)(end - begin);
        }
        for (int i = 0; i < e; i++)
        {
            for (int j = 0; j < e; j++)
            {
                printf("%d\t", d[i][j]);
            }
            printf("\n");
        }
    }
    int score = 0;
    if (checkMagic(&d[0][0], e) == 0)
    {
        printf("Your score is 0\n");
    }
    else
    {
        score = time_spent + alters * 100;
        printf("Your score is %d\n", score);
    }
}
