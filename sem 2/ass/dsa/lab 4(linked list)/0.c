#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head;
void insert(int x){
    struct Node* temp= (struct  Node*)malloc(sizeof (struct Node));
    temp->data = x;
    temp->next = head; 
    head=temp;
}
void print(){
    struct Node* temp = head;
    printf("list:");
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp =temp->next;
    }
    printf("\n");
}
int main(){
    head=NULL;//empty list 
    int n,i,x;
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&x);
    
    insert(x);
    print();
    }   
}