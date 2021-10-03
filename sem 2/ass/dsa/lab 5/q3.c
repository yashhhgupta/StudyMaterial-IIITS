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
