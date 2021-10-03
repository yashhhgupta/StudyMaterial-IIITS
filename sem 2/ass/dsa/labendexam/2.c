#include <stdio.h>
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void solve()
{
    int arr[] = {3, 8, 9, 5, 6, 2};
    int n = 6;
    printf("\nOrignal Array:- \n");
    print_array(arr, n);
    printf("\nArray at each iterations:-\n");
    int temp = 0;
    int x;
    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (temp == 0)
            {
                for (int j = 0; j < n; j = j + 2)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        x = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = x;
                    }
                }
                temp = 1;
            }
            else
            {
                for (int j = 1; j < n - 1; j = j + 2)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        x = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = x;
                    }
                }
                temp = 0;
            }
            if (i == 5)
            {
                printf("\nFinal Array\n");
            }
            print_array(arr, n);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (temp == 0)
            {
                for (int j = 0; j < n - 1; j = j + 2)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        x = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = x;
                    }
                }
                temp = 1;
            }
            else
            {
                for (int j = 1; j < n; j = j + 2)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        x = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = x;
                    }
                }
                temp = 0;
            }
            if (i == 5)
            {
                printf("\nFinal Array\n");
            }

            print_array(arr, n);
        }
    }
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void Q2_Solution()
{
    // Q2_ Solution code goes here
    int n = 7, x;
    int array[7] = {3, 8, 9, 5, 6, 2, 10};
    for (int i = 0; i < n; i++)
    { // n= 7 : 0 2 4 6  2*n
        if (i % 2 == 0)
        {
            for (int j = 0; j <= n / 2; j++)
            {
                x = 2 * j;
                if (x+1 < n && array[x] > array[x + 1])
                {
                    swap(&array[x], &array[x + 1]);
                }
            }
        }
        else
        {
            for (int j = 0; j < n / 2; j++)
            {
                x = 2 * j + 1;
                if (x+1 < n && array[x] > array[x + 1])
                {
                    swap(&array[x], &array[x + 1]);
                }
            }
        }
        printArray(array, n);
    }
    printf("\n");
}
int main()
{
    solve();
    Q2_Solution()
}