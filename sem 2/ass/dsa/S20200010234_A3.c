//question 1
#include <stdio.h>
int linearsearch(int array[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int unsortedarray[] = {3, 9, 8, 0, 5, 6, 1, 2, 7, 4};
    int key;
    printf("enter the number you want to search");
    scanf("%d", &key);
    int n = sizeof(unsortedarray) / sizeof(unsortedarray[0]);
    printf("Index of key in unsorted array is %d\n", linearsearch(unsortedarray, n, key));
    int sortedarray[]={0,1,2,3,4,5,6,7,8,9};
    printf("Index of key in sorted array is %d\n", linearsearch(sortedarray, n, key));
    return 0;
}
    //The complexity of the unsortedarray is O(n)
    //The complexity of the sortedarray is O(n)

//question 2
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int array[10];
    int n = sizeof(array) / sizeof(int);
    int j = 3;
    for (int i = 0; i < n; i++)
    {
        if (i != j)
        {
            array[i] = rand();
        }
    }
    int num, x;
    printf("enter the number and position where you want to insert\n");
    scanf("%d %d", &num, &x);
    if (x == j)
    {
        array[j] = num;
    }
    else if (x < j)
    {
        for (int i = x; i < j; i++)
        {
            array[i] = array[i + 1];
        }
        array[x] = num;
    }
    else if (x > j)
    {
        for (int i = j; i < x; i++)
        {
            array[i] = array[i + 1];
        }
        array[x] = num;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}
/* The Modified Insert algorithm consists of three cases:-
       (1)  When the location where element has to be inserted is same as the location vacant space in array;- In this case the elemnt will be inserted in the vacant location without any issues.
       (2)  When the location where element has to be inserted is ahead of the location vacant space in array:- In this case firstly the elements between the location entered and the vacant space are shifted a location before and after that the element is inserted in the vacant space generated due to shifting.
       (3) When the location where element has to be inserted is before the location vacant space in the array:- In this case firstly the elements between the location entered and the vacant space are shifted a location ahead and after that the elements is inserted in the vacant space generated due to shifting at the entered location.
*/

//question 3
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

//question 4

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


