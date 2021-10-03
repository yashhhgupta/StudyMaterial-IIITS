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
    printf("Concatenated list:");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
struct node *concatenate(struct node *head1, struct node *head2)
{
    struct node *temp;
    temp=head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        
    }
    
    temp->next = head2;
    return head1;
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
  


int main()
{
    struct node *a,*b;
    printf("enter list 1")
    a=create_list(a); 
    printf("enter list 2")

    b=create_list(b); 
    a=concatenate(a, b);
    print(a);
}