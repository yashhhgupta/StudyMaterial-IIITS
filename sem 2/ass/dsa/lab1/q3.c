#include <stdio.h>
#include <stdlib.h>
void scale_check(int arr[5][5]);

void findm(int arr[5][5]);

int main()
{
    int arr[5][5];
    printf("information grey scale [0-255]\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    scale_check(arr);
    findm(arr);
}
void scale_check(int arr[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j]/=32;
        }
    }
}
void findm(int arr[5][5])
{
    int max = 0, min = 255, mean=0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (min > arr[i][j])
            {
                min = arr[i][j];
            }
            if (max < arr[i][j])
            {
                max = arr[i][j];
            }
            mean+=arr[i][j];
        }
    }
    mean/=25;
    printf("mean intensity: %d\n",mean);
    printf("max intensity: %d\n",max);
    printf("min intensity: %d\n",min);
}