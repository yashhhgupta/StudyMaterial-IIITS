// DSA  Lab Exam
// Name  : Yash Gupta
// Roll NO: S20200010234

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};
struct queue *front = NULL;
struct queue *rear = NULL;
void enqueue(int val)
{
    struct queue *n = (struct queue *)malloc(sizeof(struct queue));

    n->data = val;
    n->next = NULL;
    if (front == NULL)
    {
        front = rear = n;
    }
    else
    {
        rear->next = n;
        rear = n;
    }
}
int dequeue()
{
    int val = -1;
    struct queue *ptr = front;
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        front = front->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
void queue_view(struct queue *ptr)
{
    printf("Printing the elements of the queue\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}
struct stack
{
    int data;
    struct stack *next;
};
int isEmpty(struct stack *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct stack *push(struct stack *ptr, int data)
{
    struct stack *n = (struct stack *)malloc(sizeof(struct stack));
    n->data = data;
    n->next = ptr;
    ptr = n;
    return ptr;
}
int pop(struct stack **ptr)
{
    struct stack *n = (struct stack *)malloc(sizeof(struct stack));
    n = *ptr;
    *ptr = (*ptr)->next;
    int x = n->data;
    free(n);
    return x;
}
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void heapify(int arr[], int n, int i)
{
    int small = i;
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;

    if (lchild < n && arr[lchild] < arr[small])
    {
        small = lchild;
    }
    if (rchild < n && arr[rchild] < arr[small])
    {
        small = rchild;
    }
    if (small != i)
    {
        int x = arr[i];
        arr[i] = arr[small];
        arr[small] = x;
        heapify(arr, n, small);
    }
}

void Q1_Solution()
{
    // Q1_ Solution code goes here
    int k = 7;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    printf("Number of elements to be reveresed %d\n\n", k);
    queue_view(front);
    struct stack *top = NULL;
    for (int j = 0; j < k; j++)
    {
        int val = dequeue();
        top = push(top, val);
    }
    int arr[10 - k];
    for (int j = 0; j < 10 - k; j++)
    {
        arr[j] = dequeue();
    }
    for (int j = 0; j < k; j++)
    {
        int value = pop(&top);
        enqueue(value);
    }
    for (int j = 0; j < 10 - k; j++)
    {
        enqueue(arr[j]);
    }
    queue_view(front);
    printf("Time complexity is O(N)\n");
}
void Q2_Solution()
{
    int arr[] = {3, 8, 9, 5, 6, 2};
    int n = 6;
    printf("\nOrignal Array:- \n");
    print_array(arr, n);
    printf("\nArray at each iterations:-\n");
    int temp = 0;
    int x;
    if (n % 2 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (temp == 0)
            {
                for (int j = 0; j < n - 1; j = j + 2)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        x = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = x;
                    }
                }
                temp = 1;
            }
            else
            {
                for (int j = 1; j < n; j = j + 2)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        x = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = x;
                    }
                }
                temp = 0;
            }
            if (i == 5)
            {
                printf("\nFinal Array:-\n");
            }

            print_array(arr, n);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (temp == 0)
            {
                for (int j = 0; j < n; j = j + 2)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        x = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = x;
                    }
                }
                temp = 1;
            }
            else
            {
                for (int j = 1; j < n - 1; j = j + 2)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        x = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = x;
                    }
                }
                temp = 0;
            }
            if (i == 5)
            {
                printf("\nFinal Array\n");
            }
            print_array(arr, n);
        }
    }

    printf("Time complexity is O(N^2)\n");
}
void Q3_Solution()
{
    int a[] = {4, 9, 12, 2, 1, 10};
    int n = 6;
    int k = 6;
    printf("Initial array(k = %d): \n\n", k);
    print_array(a, n);
    for (int j = n / 2 - 1; j >= 0; j--)
    {
        heapify(a, 6, j);
    }
    while (a[0] < k && n > 1)
    {
        if (n == 2)
        {
            a[0] += a[1];
            n--;
            break;
        }
        if (a[1] > a[2])
        {
            a[0] += a[2];
            if (n > 3)
            {
                a[2] = a[n - 1];
            }
            n--;
            if (n > 2)
            {
                heapify(a, n, 2);
            }
        }
        else
        {
            a[0] += a[1];
            a[1] = a[n - 1];
            n--;
            heapify(a, n, 1);
        }
    }
    printf("Final array with elements greater than k:\n\n");
    print_array(a, n);
    printf("Time complexity is O(nlogn)\n");
}
int main(void)
{

    int user_input = 1;
    // infinite loop
    do
    {
        printf("\n\n 0. Quit");
        printf("\n 1. Q-1 Solution ");
        printf("\n 2. Q-2 Solution");
        printf("\n 3. Q-3 Solution");
        printf("\n Enter your choice: ");
        scanf("%d", &user_input);
        switch (user_input)
        {
        case 1:
            Q1_Solution();
            break;
        case 2:
            Q2_Solution();
            break;
        case 3:
            Q3_Solution();
            break;
        }
    } while (user_input != 0);
    return 0;
}