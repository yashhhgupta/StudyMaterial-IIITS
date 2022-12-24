#include <stdio.h>
void swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        bubbleSort(arr, n);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            while (arr[i] == arr[i + 1])
            {
                i++;
            }
            count++;
        }
        if (count == k)
        {
            printf("Good\n");
        }
        else if (count > k)
        {
            printf("Average\n");
        }
        else
        {
            printf("Bad\n");
        }
    }
    return 0;
}