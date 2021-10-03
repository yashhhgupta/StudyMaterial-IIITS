//Q1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

void push(int a[], int *top, int data, int type)
{
    if (*top == MAX)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        a[*top] = data;
        *top = *top + 1;
        if (type == 1)
            printf("Successfully Inserted\n");
    }
}

void pop(int a[], int *top)
{
    if (*top == 0)
    {
        printf("Stack Underflow\n");
        return;
    }
    else
    {
        *top = *top - 1;
        printf("Succesfully popped\n");
        printf("Popped element :- %d", a[*top + 1]);
    }
}

int popQueue(int a[], int *top)
{
    if (*top == 0)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        int ans = a[0];
        for (int i = 0; i < *top - 1; i++)
        {
            a[i] = a[i + 1];
        }

        a[*top - 1] = 0;
        *top = *top - 1;
        return ans;
    }
}

void stackImplementation(int a[], int b[], int *top1, int *top2)
{
    if (*top1 == 0)
    {
        printf("Stack Underflow\n");
        return;
    }
    int ref, ans, var = *top1;
    for (int i = 0; i < var - 1; i++)
    {
        ref = popQueue(a, top1);
        push(b, top2, ref, 0);
    }
    ref = popQueue(a, top1);
    var = *top2;
    for (int i = 0; i < var; i++)
    {
        ans = popQueue(b, top2);
        push(a, top1, ans, 0);
    }
    printf("Succesfully popped element %d\n", ref);
    return;
}

int main()
{
    srand((unsigned int)time(NULL));
    int queue1[MAX], queue2[MAX];
    int top1 = 0, top2 = 0;
    int user;
    printf("Which operation you want to perform among the following\nEnter the number beside that\n");
    printf("1:Push  2:Pop 3: Exit\n");
    scanf("%d", &user);
    int data, ans;
    while (user != 3)
    {
        switch (user)
        {
        case 1:
            printf("Enter the data you want to push\n");
            scanf("%d", &data);
            push(queue1, &top1, data, 1);
            for (int i = 0; i < top1; i++)
            {
                printf("%d\n", queue1[i]);
            }
            break;
        case 2:
            stackImplementation(queue1, queue2, &top1, &top2);
            break;
        default:
            break;
        }
        printf("Which operation you want to perform among the following\nEnter the number beside that\n");
        printf("1:Push  2:Pop 3: Exit\n");
        scanf("%d", &user);
    }
    printf("the time complexity is O(n)");
}

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

//  Q3

#include <stdio.h>
#include <stdlib.h>
struct Node 
{
  int data;
  struct Node *next;
};

void push(struct Node **top, int value)
{
  struct Node *newNode;
  newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = value;
  if(*top == NULL)
    newNode->next = NULL;
  else
    newNode->next = *top;
  *top = newNode;

}

void pop(struct Node **top)
{
  if(top == NULL)
    printf("\nStack is Empty\n");
  else
  {
    struct Node *temp = *top;
    *top = temp->next;
    free(temp);
  }

}

void enqueue(struct Node **front, struct Node **rear, int val)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(*front == NULL && *rear == NULL)
    {
        
        *front = newNode;
        *rear = newNode;
    }  
    else
    {
        (*rear)->next = newNode; 
        *rear = newNode; 
    }
}

void dequeue(struct Node **front, struct Node **rear)
{

    struct Node *temp;

    if(*front == NULL)
         printf("Queue is Empty. \n");
    else
    {
        temp = *front;

        *front = (*front)->next;


        if(*front == NULL)
            *rear = NULL;

       free(temp);
    }

}

void tranverse(struct Node* p)
{
    while (p!=NULL)
    {
        printf("Data is : %d\n",p->data);
        p=p->next;
    }
}

void game(struct Node **p2, struct Node **p1, struct Node **p1_rear, struct Node **output_front, struct Node **output_rear)
{
  while((*p2) != NULL && (*p1) != NULL)
  {
    if((*p2)->data > (*p1)->data)
    {
      enqueue(output_front, output_rear,1);
      dequeue(&(*p1),&(*p1_rear));
    }
    else if((*p2)->data < (*p1)->data)
    {
      enqueue(output_front, output_rear,2);
      pop(&(*p2));

    }
    else if((*p2)->data == (*p1)->data)
    {
      enqueue(output_front, output_rear,0);      
      pop(&(*p2));
      dequeue(&(*p1),&(*p1_rear));
    }
  }
  
}


int main(void) {
  
  struct Node *player2=NULL;
  int given_list[] = {3,7,43,1,7,3,9};
  int n;
  n = sizeof(given_list)/sizeof(int);
  struct Node *player1_front = NULL;
  struct Node *player1_rear = NULL;
  struct Node *output_front = NULL;
  struct Node *output_rear = NULL;
  for(int i=0;i<n;i++)
  {
    push(&player2, given_list[i]);
    enqueue(&player1_front, &player1_rear, given_list[i]);
  }
  printf("______________________________________________");
  printf("\nStack\n");
  tranverse(player2);
  printf("\nQueue\n");
  tranverse(player1_front);
  printf("______________________________________________");
  game(&player2 ,&player1_front, &player1_rear, &output_front, &output_rear);
  printf("\nOutput List: \n \n");
  tranverse(output_front);
  printf("\nEND\n");
  return 0;
}
