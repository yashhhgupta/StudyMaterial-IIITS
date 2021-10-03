#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *createlist(){
    printf("enter the number of elements in your list\n");
    int n,i;
    scanf("%d",&n);
    printf("enter your list\n");
    struct node *head ,*temp;
    for (int i = 0; i < n; i++)
    {
        if (i==0)
        {
            head=malloc(sizeof(struct node));
            temp=head; 
        }
        else
        {
            temp->next=malloc(sizeof(struct node));
            temp=temp->next;
        }
        scanf("%d",&temp->data);
    }
    temp->next=NULL;
    return head;
}
struct node *insertion_at_start(struct node *head,int x)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->next=head;
    return temp;
}
struct node *insertion_at_last(struct node *head,int x)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->next=head;
    return temp;
}
void print(struct node *head){
    printf("\nyour list\n");
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }  
}
int main(){
    int x;
    struct node *a;
    a=createlist();
    print(a);
    printf("\nenter the value you want to add at start\n");
    scanf("%d",&x);
    a=insertion_at_start(a,x);
    print(a);
}

