#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

void push(int a[], int *top, int data, int type)
{
    if (*top == MAX)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        a[*top] = data;
        *top = *top + 1;
        if (type == 1)
            printf("Successfully Inserted\n");
    }
}

void pop(int a[], int *top)
{
    if (*top == 0)
    {
        printf("Stack Underflow\n");
        return;
    }
    else
    {
        *top = *top - 1;
        printf("Succesfully popped\n");
        printf("Popped element :- %d", a[*top + 1]);
    }
}

int popQueue(int a[], int *top)
{
    if (*top == 0)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        int ans = a[0];
        for (int i = 0; i < *top - 1; i++)
        {
            a[i] = a[i + 1];
        }

        a[*top - 1] = 0;
        *top = *top - 1;
        return ans;
    }
}

void stackImplementation(int a[], int b[], int *top1, int *top2)
{
    if (*top1 == 0)
    {
        printf("Stack Underflow\n");
        return;
    }
    int ref, ans, var = *top1;
    for (int i = 0; i < var - 1; i++)
    {
        ref = popQueue(a, top1);
        push(b, top2, ref, 0);
    }
    ref = popQueue(a, top1);
    var = *top2;
    for (int i = 0; i < var; i++)
    {
        ans = popQueue(b, top2);
        push(a, top1, ans, 0);
    }
    printf("Succesfully popped element %d\n", ref);
    return;
}

int main()
{
    srand((unsigned int)time(NULL));
    int queue1[MAX], queue2[MAX];
    int top1 = 0, top2 = 0;
    int user;
    printf("Which operation you want to perform among the following\nEnter the number beside that\n");
    printf("1:Push  2:Pop 3: Exit\n");
    scanf("%d", &user);
    int data, ans;
    while (user != 3)
    {
        switch (user)
        {
        case 1:
            printf("Enter the data you want to push\n");
            scanf("%d", &data);
            push(queue1, &top1, data, 1);
            for (int i = 0; i < top1; i++)
            {
                printf("%d\n", queue1[i]);
            }
            break;
        case 2:
            stackImplementation(queue1, queue2, &top1, &top2);
            break;
        default:
            break;
        }
        printf("Which operation you want to perform among the following\nEnter the number beside that\n");
        printf("1:Push  2:Pop 3: Exit\n");
        scanf("%d", &user);
    }
}