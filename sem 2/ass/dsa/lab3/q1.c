#include <stdio.h>
int linearsearch(int array[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int unsortedarray[] = {3, 9, 8, 0, 5, 6, 1, 2, 7, 4};
    int key;
    printf("enter the number you want to search");
    scanf("%d", &key);
    int n = sizeof(unsortedarray) / sizeof(unsortedarray[0]);
    printf("Index of key in unsorted array is %d\n", linearsearch(unsortedarray, n, key));
    int sortedarray[]={0,1,2,3,4,5,6,7,8,9};
    printf("Index of key in sorted array is %d\n", linearsearch(sortedarray, n, key));
    return 0;
}
/*  The complexity of the unsortedarray is O(n)
    The complexity of the sortedarray is O(n)
*/

