#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;

    struct node *prev;
    struct node *next;
} * head, *last;
void displayListFromEnd()
{
    struct node * temp;
    int n = 0;

    if(last == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = last;
        printf("\n\n REVERSED DATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of last-%d node = %d\n", n, temp->data);

            n++;
            temp = temp->prev; 
        }
    }
}
struct node *createlist()
{
    int i, data, n;
    struct node *newNode;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    if (n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if (head != NULL)
        {
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            last = head;

            for (i = 2; i <= n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));
                if (newNode != NULL)
                {
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = last;
                    newNode->next = NULL;

                    last->next = newNode; 
                    last = newNode;     
                }
                else
                {
                    break;
                }
            }
        }
    }

    return newNode;
}

int main()
{
    printf("enter your list\n");
    struct node *a;
    a = createlist(a);
    displayListFromEnd(a);
}
//THE TIME COMPLEXITY OF THE PROGRAM IS O(N)