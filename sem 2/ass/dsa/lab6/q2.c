#include <stdio.h>
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

}