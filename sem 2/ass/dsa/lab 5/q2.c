//Q2
#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack* next;
};
int num=0;

struct stack* push(struct stack* p)
{   
    int item;
    struct stack* temp=(struct stack*)malloc(sizeof(struct stack));
    printf("Enter data\n");
    scanf("%d",&item);
    temp->data=item;
    temp->next=p;
    p=temp;
    
    return p;
    
}
struct stack* pop(struct stack* p)
{
    struct stack* temp=p;
    printf("Deleted element is %d\n",temp->data);
    p=p->next;
    free(temp);
    return(p);

}
void tranverse(struct stack* p)
{
    while (p!=NULL)
    {
        printf("Data is : %d\n",p->data);
        p=p->next;
    }
    
}
int checkempty(struct stack *p)
{
    if(p==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void main()
{
    struct stack* top,*top2;
    top=NULL;
    top2=NULL;
    int n;
    printf("Enter No. of elements in array\n");
    scanf("%d",&n);
    int count=0;

    while(1)
    {
        int opinion;
        printf("1.push\n2.pop\n3.display\nany option exit\n");
        scanf("%d",&opinion);
        switch (opinion)
        {
        case 1:
            if(count<n/2)
            {
                top=push(top);
            }
            else if (count<n)
            {
                top2=push(top2);
            }
            else
            {
                printf("Overflow - No more item can be added\n");
            }
            count+=1;
            break;
        case 2:
            if(!checkempty(top2))
            {
                top2=pop(top2);
            }
            else if(!checkempty(top))
            {
                top=pop(top);
            }
            else
            {
                printf("Both stacks are empty\n");
            }

        break;
        case 3:
            if(!checkempty(top2))
            {
                tranverse(top2);
            }
            if(!checkempty(top))
            {
                tranverse(top);
            }
            else
            {
                printf("Both stacks are empty\n");
            }
        break;
        default:
            exit(1);
        }
    }
}