//QUESTION1
/*
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
*/

//QUESTION2
/*#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

struct node *rr = NULL;
struct node *fr = NULL;
struct node *temp, *newNode;

void create()
{
    fr = rr = NULL;
}

void enqueue(int data)
{
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (fr == NULL)
        fr = rr = newNode;
    else
    {
        rr->next = newNode;
        rr = newNode;
    }
    rr->next = fr;
}

int dequeue()
{
    int x;
    if (fr == NULL)
    {
        return -1;
    }
    else if (fr == rr)
    {
        x = fr->data;
        free(fr);
        fr = rr = NULL;
    }
    else
    {
        node *temp = fr;
        x = temp->data;
        fr = fr->next;
        rr->next = fr;
        free(temp);
    }
    return x;
}

int empty()
{
    if (fr == NULL)
    {
        return 1;
    }
    else
        return 0;
}

void print()
{
    node *temp = fr;
    printf("\nCIRCULAR QUEUE : ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != fr);
    printf("\n");
}

void reverseq()
{
    node *temp = fr, *curr, *prev = rr;
    do
    {
        curr = temp;
        temp = temp->next;
        curr->next = prev;
        prev = curr;
    } while (temp != fr);
    temp = fr;
    fr = rr;
    rr = temp;
}

int main()
{
    int num, choice;
    while (1)
    {
        printf("Queue Operations:- \n1) ENQUEUE\n2) DEQUEUE\n3) print \n4) REVERSE\n5) TIME COMPLEXITY ");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter item : ");
            scanf("%d", &num);
            enqueue(num);
            break;
        case 2:
            if (!(empty()))
                printf("\nDequeued element : %d", dequeue());
            else
                printf("\nEMPTY QUEUE\n");
            break;
        case 3:
            print();
            break;
        case 4:
            reverseq();
            break;
        case 5:
            printf("TIME COMPLEXITY IS O(N)\n");
        default:
            exit(0);
        }
    }

} */
//QUESTION 3
/*#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *fr = NULL;
struct node *rr = NULL;

void enqueue(int n)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = n;
    new->next = NULL;
    if ((rr == NULL) && (fr == NULL))
    {
        fr = rr = new;
        rr->next = fr;
    }
    else
    {
        rr->next = new;
        rr = new;
        new->next = fr;
    }
}

void dequeue()
{
    struct node *temp;
    temp = fr;
    if ((fr == NULL) && (rr == NULL))
    {
        printf("\nQueue is Empty");
    }
    else if (fr == rr)
    {
        fr = rr = NULL;
        free(temp);
    }
    else
    {
        fr = fr->next;
        rr->next = fr;
        free(temp);
    }
}

int main()
{
    int c = 0, n = 2, q = 11;
    char o;
    printf("Enter the operations\n");
    for (int i = 0; i < q; i++)
    {
        scanf("\n");
        int num;
        scanf("%c", &o);
        if (o == 'E')
        {
            scanf("%d", &num);
        }
        switch (o)
        {
        case 'E':
            if (c < n)
            {
                enqueue(num);
                c++;
            }
            else
            {
                printf("Overflow\n");
            }
            break;

        case 'D':
            if (c == 0)
            {
                printf("Underflow\n");
            }
            else
            {
                dequeue();
                c--;
            }
            break;

        case 'F':
            if (c == 0)
            {
                printf("Empty\n");
            }
            else
            {
                printf("%d\n", fr->data);
            }
            break;

        case 'R':
            if (c == 0)
            {
                printf("Empty\n");
            }
            else
            {
                printf("%d\n", rr->data);
            }
            break;
    
        default:
            printf("Invalid operation");
        }
    }
    printf("TIME COMPLEXITY IS O(N)\n");
    return 0;
}*/
