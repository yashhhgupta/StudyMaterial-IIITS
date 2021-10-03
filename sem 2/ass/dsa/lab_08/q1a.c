//Q.1////////
#include <stdio.h>  
#include <stdlib.h>


struct BST_node
{
  int data;
  struct BST_node * lchild;
  struct BST_node * rchild;
};
struct BST_node* create_node(int data){
    struct BST_node* node =(struct BST_node*) malloc(sizeof(struct BST_node));

    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

struct BST_node *insert(struct BST_node *head, int d)
{
    if (head == NULL)
    {
        head = create_node(d);
    }
    else if (head->data >= d)
    {
        head->lchild = insert(head->lchild, d);
    }
    else if (head->data < d)
    {
        head->rchild = insert(head->rchild, d);
    }
    return head;
}

struct BST_node * construct_BST (int arr[], int n, struct BST_node * root)
{
  root = create_node(arr[0]);
  struct BST_node* ref;
  for(int i = 1; i < n; i++){
    insert(root, arr[i]);
  }
  return root;
}


void print_tree(struct BST_node * root)
{
      if(root!=NULL){
        print_tree(root->lchild);
        printf("%d ",root->data);
        print_tree(root->rchild);
    }
}

struct BST_node* delete_BST(struct BST_node* root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->lchild = delete_BST(root->lchild, data);

    else if (data > root->data)
        root->rchild = delete_BST(root->rchild, data);
 
    else {

        if (root->lchild == NULL) {
            struct BST_node* temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL) {
            struct BST_node* temp = root->lchild;
            free(root);
            return temp;
        }

        struct BST_node* current = root->rchild;
 
        while (current && current->lchild != NULL)
        current = current->lchild;

        struct BST_node* temp = current;

        root->data = temp->data;
        root->rchild = delete_BST(root->rchild, temp->data);
    }
    return root;
}

int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int BST_height(struct BST_node *head)
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        return 1 + max(BST_height(head->rchild), BST_height(head->lchild));
    }
}


int main()
{
  int arr[] = {4,6,3,67,7,2,77,27,98};
  int n =sizeof(arr)/sizeof(arr[0]);
  struct BST_node* root = NULL;
  root = construct_BST(arr, n, root);
  print_tree(root);
  printf("\n------------------------------\n");

  delete_BST(root,4);
  print_tree(root);
  printf("\n------------------------------\n");
  printf("%d\n",BST_height(root));
  return 0;

}