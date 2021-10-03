#include<stdio.h>
#include<stdlib.h>

struct list 
{
    int data;
    struct list* next;
};
struct list *add(struct list *head1,struct list *head2)
{
    struct list *temp=(struct list*)malloc(sizeof(struct list));
    struct list *x=head1,*y=head2,*z=temp;
    for (int i = 0; ; i++)
    {   
        if(x==NULL && y==NULL)
        {
            break;
        }
        if (i == 0)
        {
            if(x!=NULL || y!=NULL)
            {
                if(x!=NULL && y!=NULL)
                {
                    temp->data=y->data+x->data;
                }
                else if(x!=NULL)
                {
                    temp->data=x->data;
                }
                else if(y!=NULL)
                {
                    temp->data=y->data;
                }
            }
        }
        else
        {
            temp->next = (struct list*)malloc(sizeof(struct list));
            temp = temp->next;
            if(x!=NULL || y!=NULL)
            {
                if(x!=NULL && y!=NULL)
                {
                    temp->data=y->data+x->data;
                }
                else if(x!=NULL)
                {
                    temp->data=x->data;
                }
                else if(y!=NULL)
                {
                    temp->data=y->data;
                }
                
            }

        }
        if(x!=NULL)
        {
            x=x->next;
        }
        if(y!=NULL)
        {
            y=y->next;
        }
        
    }
    temp->next = NULL;
    return z;
}
struct list *sub(struct list *head1,struct list *head2)
{
    struct list *temp=(struct list*)malloc(sizeof(struct list));
    struct list *x=head1,*y=head2,*z=temp;
    for (int i = 0; ; i++)
    {   
        if(x==NULL && y==NULL)
        {
            break;
        }
        if (i == 0)
        {
            if(x!=NULL || y!=NULL)
            {
                if(x!=NULL && y!=NULL)
                {
                    temp->data=-1*(y->data)+x->data;
                }
                else if(x!=NULL)
                {
                    temp->data=x->data;
                }
                else if(y!=NULL)
                {
                    temp->data=-1*(y->data);
                }
            }
        }
        else
        {
            temp->next = (struct list*)malloc(sizeof(struct list));
            temp = temp->next;
            if(x!=NULL || y!=NULL)
            {
                if(x!=NULL && y!=NULL)
                {
                    temp->data=-1*(y->data)+x->data;
                }
                else if(x!=NULL)
                {
                    temp->data=x->data;
                }
                else if(y!=NULL)
                {
                    temp->data=-1*(y->data);
                }
                
            }

        }
        if(x!=NULL)
        {
            x=x->next;
        }
        if(y!=NULL)
        {
            y=y->next;
        }
        
    }
    temp->next = NULL;
    return z;
}
int main()
{   
    struct list *head1=(struct list*)malloc(sizeof(struct list));
    struct list *second1=(struct list*)malloc(sizeof(struct list));
    struct list *third1=(struct list*)malloc(sizeof(struct list));
    head1->data=5;
    head1->next=second1;
    second1->data=6;
    second1->next=third1;
    third1->data=7;
    third1->next=NULL;
    struct list *head2=(struct list*)malloc(sizeof(struct list));
    struct list *second2=(struct list*)malloc(sizeof(struct list));
    struct list *third2=(struct list*)malloc(sizeof(struct list));
    head2->data=8;
    head2->next=second2;
    second2->data=1;
    second2->next=third2;
    third2->data=2;
    third2->next=NULL;
    struct list *p,*a3,*s3;
    p=head1;
    printf("First polynomial\n");
    while (p!=NULL)
    {
        printf("Data is : %d\n",p->data);
        p=p->next;
    }
    p=head2;
    printf("Second polynimal\n");
    while (p!=NULL)
    {
        printf("Data is : %d\n",p->data);
        p=p->next;
    }
    a3=add(head1,head2);
    p=a3;
    printf("add polynimal\n");
    while (p!=NULL)
    {
        printf("Data is : %d\n",p->data);
        p=p->next;
    }
    s3=sub(head1,head2);
    p=s3;
    printf("add polynimal\n");
    while (p!=NULL)
    {
        printf("Data is : %d\n",p->data);
        p=p->next;
    }
    return 0;
}