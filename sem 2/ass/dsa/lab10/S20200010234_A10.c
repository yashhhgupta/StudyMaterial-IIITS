#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
//Question1(insertion)
void insertSort(int arr[], int n)
{
    int j;
    int key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}
//Question2(selection)
void selection_sort(int A[], int n)
{
    int small;
    for (int j = 0; j < n - 1; j++)
    {
        small = j;
        for (int i = j + 1; i < n; i++)
        {
            if (A[i] < A[small])
            {
                small = i;
            }
        }
        swap(&A[j], &A[small]);
    }
}
//Question2(bubble)
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

//Question3(merge sort)
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

// Question 4
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head;
Node *sorted_head;

void instertionSort(Node *ref)
{
    sorted_head = NULL;
    Node *current = ref;
    while (current != NULL)
    {
        Node *next = current->next;

        if (sorted_head == NULL || sorted_head->data >= current->data)
        {
            current->next = sorted_head;
            sorted_head = current;
        }
        else
        {
            Node *curr = sorted_head;
            while (curr->next != NULL && curr->next->data < current->data)
            {
                curr = curr->next;
            }
            current->next = curr->next;
            curr->next = current;
        }

        current = next;
    }
    head = sorted_head;
    while (head != NULL)
    {
        printf("%02d\t", head->data);
        head = head->next;
    }
}
//printing the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%02d\t", arr[i]);
    }
    printf("\n");
}
int main(void)
{
    int orig[50], insert[50], selection[50], bubble[50];
    head = (struct Node *)malloc(sizeof(struct Node));
    Node *q = head;
    for (int i = 0; i < 50; i++)
    {
        orig[i] = rand() % 99 + 1;
        selection[i] = orig[i];
        bubble[i] = orig[i];
        insert[i] = orig[i];
        q->data = orig[i];
        if (i != 49)
        {
            q->next = (Node *)malloc(sizeof(Node));
        }
        else
        {
            q->next = NULL;
        }
        q = q->next;
    }
    //-------------------------------------------------------------
    //-------------------------------------------------------------
    //-------------------------------------------------------------
    //Question1

    printf("\nOrignal array\n");
    printArray(orig, 50);
    //insertSort
    printf("\nQuestion 1\n");
    printf("\nSorting using insert sort\n");
    insertSort(insert, 50);
    printArray(insert, 50);
    printf("Time complexity of insertion sort = O(n^2)");
    //-------------------------------------------------------------
    //-------------------------------------------------------------
    //-------------------------------------------------------------
    //Question 2
    printf("\nQuestion 2\n");
    //selection_sort
    printf("\na)Sorting using selection sort\n");
    double start = clock();
    selection_sort(selection, 50);
    double end = clock();
    printArray(selection, 50);
    printf("\nSorting took %f ms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    printf("Time complexity of selection sort = O(n^2)");
    //bubbleSort
    printf("\nb)Sorting using bubble sort\n");
    start = clock();
    bubbleSort(bubble, 50);
    end = clock();
    printArray(bubble, 50);
    printf("\nSorting took %f ms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    printf("Time complexity of bubble sort = O(n^2)");
    //-------------------------------------------------------------
    //-------------------------------------------------------------
    //-------------------------------------------------------------
    //Question3
    printf("\nQuestion 3\n");
    int arr2[] = {-33, 0, 1, 2, 7, 12, 17, 19, 21, 35};
    printf("\nsorting using merge sort\na)Sorted array\n");
    printArray(arr2, 10);
    merge_sort(arr2, 0, 9);
    printf("\n");
    printArray(arr2, 10);
    printf("\nb)Reversed-order input\n");
    int arr3[10] = {94, 66, 54, 33, 21, 11, 10, 6, 5, 4};
    printArray(arr3, 10);
    printf("\n");
    merge_sort(arr3, 0, 9);
    printArray(arr3, 10);
    printf("\nc)Random input\n");
    int arr4[10];
    for (int i = 0; i < 10; i++)
    {
        arr4[i] = rand() % 99 + 1;
    }
    printArray(arr4, 10);
    printf("\n");
    merge_sort(arr4, 0, 9);
    printArray(arr4, 10);
    //-------------------------------------------------------------
    //-------------------------------------------------------------
    //-------------------------------------------------------------
    //Question4
    printf("\nQuestion4\n");
    instertionSort(head);
    printf("\n");
    printf("Time complexity of insertion sort = O(n^2)");
    return 0;
}