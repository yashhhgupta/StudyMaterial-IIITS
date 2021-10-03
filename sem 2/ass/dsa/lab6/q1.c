#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};
struct queue *push(struct queue *p, int item);
struct queue *pop(struct queue *p);
void print(struct queue *f);
void main()
{
    struct queue *front = NULL, *oddfront = NULL, *evenfront = NULL;
    struct queue *rear = NULL, *oddrear = NULL, *evenrear = NULL;
    front = rear = push(rear, 2);
    rear = push(rear, 44);
    rear = push(rear, 9);
    rear = push(rear, 18);
    rear = push(rear, 91);
    rear = push(rear, 120);
    rear = push(rear, 111);
    printf("Queue \n");
    print(front);
    struct queue *temp = front;
    for (int i = 1; temp != NULL; i++)
    {
        if (i == 1)
        {
            oddfront = oddrear = push(oddrear, temp->data);
        }
        else if(i==2)
        {
            evenfront = evenrear = push(evenrear, temp->data);

        }
        else if(i%2==0)
        {
            evenrear = push(evenrear, temp->data);
        }
        else if(i%2!=0)
        {
            oddrear = push(oddrear, temp->data);

        }
        temp=temp->next;
    }
    printf("SPLITQ\nQueue (odd position)\n");
    print(oddfront);
    printf("Queue (even position)\n");
    print(evenfront);
    printf("TIME COMPLEXITY IS O(N)\n");
}
struct queue *push(struct queue *p, int item)
{
    struct queue *node = (struct queue *)malloc(sizeof(struct queue));
    if (p == NULL)
    {
        node->data = item;
        node->next = NULL;
    }
    else
    {
        node->data = item;
        node->next = NULL;
        p->next = node;
    }

    return node;
}
struct queue *pop(struct queue *p)
{
    struct queue *temp = p;
    if (p != NULL)
    {
        p = p->next;
        free(temp);
    }
    return p;
}
void print(struct queue *f)
{
    struct queue *temp = f;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}