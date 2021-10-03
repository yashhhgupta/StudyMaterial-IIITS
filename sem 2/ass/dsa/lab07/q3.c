#include <stdio.h>

int modified_binary_search(int arr[], int n, int key, int k)
{
    int l , hi;
    if (key >= arr[0])
    {
        l = 0;
        hi = k - 1;
        while (l <= hi)
        {
            int m = (l + hi) / 2;
            if (key == arr[m])
                return m;
            else if (key > arr[m])
                l = m + 1;

            else
                hi = m - 1;
        }
    }
    if (key < arr[0])
    {
        l = k;
        hi = n - 1;
        while (l <= hi)
        {
            int m = (l + hi) / 2;
            if (key == arr[m])
                return m;
            else if (key > arr[m])
                l = m + 1;

            else
                hi = m - 1;
        }
    }
    return -1;
}
int main()
{
    int n = 5;
    int arr[5] = {3,4,5,1,2};
    int key = 4;
    int k = 3;
    printf("%d", modified_binary_search(arr, n, key, k));
    return 0;
}