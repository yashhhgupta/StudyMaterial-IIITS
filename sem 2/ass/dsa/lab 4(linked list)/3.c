#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;

    struct node *next;
} node;
void print(struct node *head)
{
    struct node *temp;
    temp = head;
    printf("Final list:");
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
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
    ptr->next = head;
    return head;
}
struct node *merge(struct node *head1, struct node *head2)
{
    struct node *temp = head1;

    while (temp->next != head1)
    {
        temp = temp->next;
    }
    temp->next = head2;
    temp = temp->next;
    while (temp->next != head2)
    {
        temp = temp->next;
    }
    temp->next = head1;
    return head1;
}
int main()
{
    printf("enter your circular list 1\n");
    struct node *a, *b;
    a = create_list(a);
    printf("enter your circular list 2\n");
    b = create_list(b);
    a = merge(a, b);
    print(a);
}