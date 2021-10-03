#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Consider "$" as an empty element in array

int A[20];
int array_size = 10;
void printArr(int k, int array_size)
{
    int i;
    int x;
    x = log2(array_size);
    x += 1;
    if (k >= x)
    {
        return;
    }
    int len = pow(2, k);
    for (i = 0; i < pow(2, k); ++i)
        if (len + i - 1 < array_size)
            printf("%d\t", A[len + i - 1]);
        else
            printf("$\t");
    printf("\n");
    printArr(k + 1, array_size);
}

void max_heapify(int A[], int array_index, int array_size)
{
    int tmp;
    int larg = array_index;
    int l = 2 * array_index + 1;
    int r = 2 * array_index + 2;
    if (l < array_size && A[l] > A[larg])
        larg = l;
    if (r < array_size && A[r] > A[larg])
        larg = r;
    if (larg != array_index)
    {
        tmp = A[array_index];
        A[array_index] = A[larg];
        A[larg] = tmp;
        max_heapify(A, larg, array_size);
    }
}

void insert(int num)
{
    if (array_size == 20)
    {
        printf("Heap has no extra space\n");
        return;
    }
    A[array_size] = num;
    array_size++;
    for (int i = array_size / 2 - 1; i >= 0; i--)
    {
        max_heapify(A, i, array_size);
    }
}

int update(int key, int alpha)
{
    int tmp = 0;
    for (int j = 0; j < array_size; j++)
    {
        if (A[j] == key)
        {
            A[j] += alpha;
            tmp = 1;
        }
    }
    if (tmp)
    {
        for (int i = array_size / 2 - 1; i >= 0; i--)
    {
        max_heapify(A, i, array_size);
    }
        return key + alpha;
    }
    else
        return -1;
}


int main(void)
{
    //Question 1
    srand((unsigned int)time(NULL));
    for (int j = 0; j < 10; j++)
    {
        A[j] = rand() % 100;
    }
    int array_index = 0;
    for (int i = array_size / 2 - 1; i >= 0; i--)
    {
        max_heapify(A, i, array_size);
    }
    printf("Q1\n\nOrignal Array\n\n");
    printArr(0, array_size);
    printf("\nTime complexity of max_heapify is logn\n");


    //Question 2
    insert(45);
    printf("Q2\n\nArray after insertion\n\n");
    printf("\nTime complexity of insert is nlogn\n");
    printArr(0, array_size);

    //Question 3
    printf("Q3\n\nUpdated Array\n\n");
    int x = update(45, 32);
    ;
    if (x == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found\nUpdated element:- %d\n", x);
    }
    printArr(0, array_size);
    printf("\nTime complexity of update is nlogn\n");

    return 0;
}