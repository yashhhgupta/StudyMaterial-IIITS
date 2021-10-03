#include <stdio.h>
#include <stdlib.h>
//Name: ARITRO GHOSH    Roll No.- S20200010021
struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

struct node *create_list()
{

    struct node *head, *tmp;
    int i, n;

    printf("How many elements you want to create:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            head = malloc(sizeof(struct node));
            tmp = head;
        }
        else
        {
            tmp->next = malloc(sizeof(struct node));
            tmp = tmp->next;
        }
        printf("Enter Node %d:", i + 1);
        scanf("%d", &tmp->data);
    }
    tmp->next = NULL;
    return (head);
}

struct node *front(struct node *head, int value)
{
    struct node *tmp;

    tmp = malloc(sizeof(struct node));
    tmp->data = value;
    tmp->next = head;
    return (tmp);
}

struct node *end(struct node *head, int value)
{
    struct node *tmp, *prev;

    tmp = malloc(sizeof(struct node));
    tmp->data = value;
    tmp->next = NULL;

    prev = head;
    while (prev->next != NULL)
    {
        prev = prev->next;
    }
    prev->next = tmp;
}

struct node *middle(struct node *a, int value)
{
    if (a->next != NULL)
    {
        struct node *tmp;
        tmp = malloc(sizeof(struct node));
        tmp->data = value;
        tmp->next = a->next;
        a->next = tmp;
    }
}

struct node *delete_front(struct node *head)
{
    struct node *tmp;
    tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

void delete_end(struct node *head)
{
    struct node *tmp, *prev_node;
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    tmp = head;
    while (tmp->next != NULL)
    {
        prev_node = tmp;
        tmp = tmp->next;
    }
    free(tmp);
    prev_node->next = NULL;
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
void delete_mid(struct node *head, int pos)
{
    struct node *temp=head;
    int x=0;
    while(x!=pos-1 && temp->next!=NULL)
    {
        temp=temp->next;
        x+=1;
    }
    struct node *delete_node=temp->next;
    temp->next=delete_node->next;
    free(delete_node);
}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

int main()
{
    struct node *head, *temp;
    head = create_list();
    head = front(head, 10);
    end(head, 50);
    middle(head->next->next, 40);

    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");

    head=delete_front(head);
    delete_end(head);

    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
    printf("enter the index of the node to be deleted\n");
    int index;
    scanf("%d",&index);
    delete_mid(head,index);
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    return 0;
}