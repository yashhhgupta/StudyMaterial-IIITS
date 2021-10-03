#include <stdio.h>
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
}