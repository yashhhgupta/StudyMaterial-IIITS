#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
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
struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void push(char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
    {
        printf("stack is full\n");
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
char pop()
{
    struct Node *t;
    char x = -1;

    if (top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int precedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }

    return 0;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int partition(int arr[], int low, int high)
{
    srand(time(NULL));
    int randomnum = low + rand() % (high - low);
    swap(&arr[randomnum], &arr[high]);
    int i = (low - 1);
    int pivot = arr[high];
    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }

    swap(&arr[high], &arr[i + 1]);
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
void solution1()
{
    int n, q, k;
    scanf("%d %d", &n, &q);
    int score[n], prize[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &prize[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &score[i]);
    }
    merge_sort(prize, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &k);
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            sum = sum + prize[n - 1 - j];
        }
        printf("%d\n", sum);
    }
}
void solution2()
{
}
void solution3()
{
    srand((unsigned)time(NULL));
    int arr[] = {22, 4, 11, 54, 3, 2, 6, 0.9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("unsorted Array:-\n");
    printArray(arr, n);
    printf("Sorted Array:-\n");
    quick_sort(arr, 0, n - 1);
    printArray(arr, n);
    printf("Time complexity is O(nlogn)\n");
}
void solution4()
{
    int arr[] = {6, 0, 8, 2, 3, 0, 4, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int newarr[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            newarr[j++] = arr[i];
        }
    }
    for (int i = j; i < n; i++)
    {
        newarr[i] = 0;
    }

    printArray(newarr, n);
}
int main()
{

    //Question 1
    printf("Question 1\n");
    solution1();
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    //Question 2
    printf("Question 2\n");
    solution2();
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    //Question 3
    printf("Question 3\n");

    solution3();

    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    //Question 4
    printf("Question 4\n");

    solution4();

    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    return 0;
}