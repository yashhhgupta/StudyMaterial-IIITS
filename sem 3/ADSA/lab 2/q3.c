#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int partition(int arr[], int low, int high)
{
    srand(time(NULL));
    int randomnum = low + rand() % (high - low);
    swap(&arr[randomnum], &arr[high]);
    int i = (low - 1);     
    int pivot =arr[high];
    for (int j = low; j <= high - 1; j++)
    {
        
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    
    swap(&arr[high], &arr[i+1]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    int index;
    if (low < high)
    {
        index = partition(arr, low, high);
        quick_sort(arr, low, index - 1);
        quick_sort(arr, index + 1, high);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    srand((unsigned)time(NULL));
    int arr[]={22,4,11,54,3,2,6,0.9};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("unsorted Array:-\n");
    printArray(arr,n);
    printf("Sorted Array:-\n");
    quick_sort(arr,0,n-1);
    printArray(arr,n);
}