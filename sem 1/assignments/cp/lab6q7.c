#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    int count1=0;
    int count2=0;
    printf("enter length of array=");
    scanf("%d",&n);
    int arr[n];
    printf("enter your array=");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    for (int j = 0; j < n; j++)
    {
        if (arr[j] % 2 == 0)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    printf("total even elements=%d\n", count1);
    printf("total odd elements=%d\n", count2);
    return 0;
}