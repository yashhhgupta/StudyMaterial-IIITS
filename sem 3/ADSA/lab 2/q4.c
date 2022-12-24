#include <stdio.h>
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={6, 0, 8, 2, 3, 0, 4, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int newarr[n];
    int j=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]!=0)
        {
            newarr[j++]=arr[i];
        }
        
    }
    for (int i = j; i < n; i++)
    {
        newarr[i] = 0;
    }
    
    printArray(newarr,n);
}