#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;

    struct node *next;
} node;
void print(struct node *head1)
{
    struct node *temp;

    temp = head1;
    printf("Final list:");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
struct node *create_list()
{
    struct node *head;
    struct node *ptr;
    int k, n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    for (k = 0; k < n; k++)
    {
        if (k == 0)
        {
            head = malloc(sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr->next = malloc(sizeof(struct node));
            ptr = ptr->next;
        }

        printf("Enter the value of node %d: ", k + 1);
        scanf("%d", &ptr->data);
    }
    ptr->next = NULL;
    return head;
}
struct node *insert_sorted(struct node *head, struct node *element)
{
    struct node *temp = head, *pre;

    int flag = 0;
    while (temp != NULL)
    {
        if (temp == head)
        {
            if ((element->data) <= (temp->data))
            {
                element->next = temp;
                head = element;
                flag = 1;
                break;
            }
        }
        else
        {
            if ((element->data) <= (temp->data))
            {
                element->next = temp;
                pre->next = element;
                flag = 1;
                break;
            }
        }
        pre = temp;
        temp = temp->next;
    }
    if (flag == 0)
    {
        pre->next = element;
        element->next = NULL;
    }
    return head;
}

int main()
{
    printf("enter your sorted list\n");
    struct node *a;
    a = create_list(a);
    printf("enter the number you want to add:\n");
    int x;
    scanf("%d", &x);
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    a = insert_sorted(a, n);
    print(a);
}