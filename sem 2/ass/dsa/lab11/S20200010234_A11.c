#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void printArray(int arr[], int n)
{
    printf("Orignal array:-\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
//Question 1
int count_sort_MP(int arr[], int n)
{
    int max = arr[0];
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int freq[max + 1];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]] += 1;
    }
    int max2 = 0, t = 0;
    for (int i = 0; i < max + 1; i++)
    {
        if (freq[i] >= max2)
        {
            max2 = freq[i];
            t = i;
        }
    }
    //Sorting the array
    for (int i = 1; i < max + 1; i++)
    {
        freq[i] += freq[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        arr2[--freq[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr2[i];
    }

    
    return t;
}
//Question 2
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);     

    for (int j = low; j <= high - 1; j++)
    {
        
        if (arr[j] < pivot)
        {
            i++;
            
            int r = arr[i];
            arr[i] = arr[j];
            arr[j] = r;
        }
    }
    
    int r = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = r;
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
void Pair_of_sum(int arr[], int n)
{

    int k = rand() % 99 + 1;
    printf("The sum to be searched: %d", k);
    int maximum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (maximum < arr[i])
            maximum = arr[i];
    }
    int digits = 0;
    while (maximum > 0)
    {
        digits++;
        maximum /= 10;
    }
    int power = 1;
    for (int i = 0; i < digits; i++)
    {
        int new_array[n];
        int count[10];
        for (int j = 0; j < 10; j++)
            count[j] = 0;
        for (int j = 0; j < n; j++)
        {
            int num = (arr[j] / power) % 10;

            count[num]++;
        }
        for (int j = 1; j < 10; j++)
        {
            count[j] += count[j - 1];
        }
        for (int j = n - 1; j >= 0; j--)
        {
            int num = (arr[j] / power) % 10;

            new_array[count[num] - 1] = arr[j];
            count[num]--;
        }
        for (int j = 0; j < n; j++)
            arr[j] = new_array[j];
        power *= 10;
    }
    int l = -1, h = -1, cnt = 0;
    printf("\nPairs generating the sum:");
    for (int i = 0; i < n && arr[i] <= k; i++)
    {
        l = i;
        for (int j = l; j < n; j++)
        {
            if (arr[l] + arr[j] == k)
            {
                h = j;
            }
            if (l != -1 && h != -1)
            {
                printf("%d %d\n", arr[l], arr[h]);
                cnt++;
            }
            h = -1;
        }
    }
    if (cnt == 0)
    {
        printf(" No such Pair found\n");
    }
}

int main()
{
    //Question 1
    printf("\nQuestion1:-\n");
    printf("\n");
    srand((unsigned int)time(NULL));
    int n = 10;
    int arr1[n], arr2[n], arr3[n];
    for (int i = 0; i < n; i++)
    {
        arr1[i] = rand() % 99 + 1;
        arr2[i] = rand() % 99 + 1;
        arr3[i] = rand() % 99 + 1;
    }
    printArray(arr1, n);
    printf("Value with max frequency = %d\n", count_sort_MP(arr1, n));
    printf("\n");
    printf("The time complexity of quick sort is O(n+k)\nThe space complexity of quick sort is O(n+k)/n\n");
    printf("---------------------------------------------------------------------------\n");

    //Question 2
    printf("\nQuestion2:-\n");
    printf("\n");
    printArray(arr2, n);
    quick_sort(arr2, 0, n - 1);
    printf("\nMaximum product of two integers(%d , %d) in array = %d\n", arr2[n - 1], arr2[n - 2], arr2[n - 1] * arr2[n - 2]);
    printf("\n");
    printf("The time complexity of quick sort is O(n^2)\nThe space complexity of quick sort is O(logn)\n");
    printf("---------------------------------------------------------------------------\n");

    //Question 3
    printf("\nQuestion3:-\n");
    printf("\n");
    printArray(arr3, n);
    printf("\n");
    Pair_of_sum(arr3, n);
    printf("\nThe time complexity of sorting array using Radix sort is O(d(n+k))\nThe space complexity of radix sort is O(n+k)\n");
    printf("---------------------------------------------------------------------------\n");
    return 0;
}