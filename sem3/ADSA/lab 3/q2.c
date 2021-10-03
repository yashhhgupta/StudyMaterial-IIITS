#include <stdio.h>
int findstudent(long long int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (x == arr[i])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        long long int arr[n + m];
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        long long int temp;
        for (int i = 0; i < m; i++)
        {
            scanf("%lld", &temp);
            if (findstudent(arr, n + i, temp))
            {
                printf("Yes\n");
                arr[n + i + 1] = temp;
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}