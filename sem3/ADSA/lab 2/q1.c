#include <stdio.h>
void merge(int a[], int i1, int i2, int j1, int j2)
{
    int tmp[50];
    int i = i1, j = j1, k = 0;

    while (i <= i2 && j <= j2)
    {
        if (a[i] < a[j])
        {
            tmp[k++] = a[i++];
        }
        else
        {
            tmp[k++] = a[j++];
        }
    }

    while (i <= i2)
    {
        tmp[k++] = a[i++];
    }

    while (j <= j2)
    {
        tmp[k++] = a[j++];
    }

    for (i = i1, j = 0; i <= j2; i++, j++)
    {
        a[i] = tmp[j];
    }
}
void merge_sort(int a[], int i, int j)
{
    int mid;

    if (i < j)
    {
        mid = (i + j) / 2;
        merge_sort(a, i, mid);
        merge_sort(a, mid + 1, j);
        merge(a, i, mid, mid + 1, j);
    }
}
int main(){
    int n,q,k;
    scanf("%d %d",&n,&q);
    int score[n],prize[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&prize[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&score[i]);
    }
    merge_sort(prize,0,n-1);
    for (int i = 0; i < q; i++)
    {
        scanf("%d",&k);
        int sum=0;
        for (int j = 0; j < k; j++)
        {
            sum=sum+prize[n-1-j];
        }
        printf("%d\n",sum);
    }
    
    return 0;
}