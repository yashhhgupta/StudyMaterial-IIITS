#include <stdio.h>
#include <stdlib.h>

struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
};
struct bstnode *FindMax(struct bstnode *root)
{
    struct bstnode *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
struct bstnode *getnewnode(int data)
{
    struct bstnode *newnode = (struct bstnode *)malloc(sizeof(struct bstnode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct bstnode *insert(struct bstnode *root, int data)
{
    if (root == NULL)
    {
        root = getnewnode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void print_tree(struct bstnode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
}
struct bstnode *delete_bst(struct bstnode *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = delete_bst(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete_bst(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            struct bstnode *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct bstnode *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            struct bstnode *temp = FindMax(root->left);
            root->data = temp->data;
            root->left = delete_bst(root->left, root->data);
        }
        return root;
    }
}
int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}
int Bst_height(struct bstnode *head)
{
    
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        return (max(Bst_height(head->left), Bst_height(head->right))+1);
    }
}
void balancedfactor(struct bstnode *head,int *count){
    if (head == NULL)
    {
        return;
    }
    int lefth=Bst_height(head->left);
    int righth=Bst_height(head->right);
    int bal=lefth-righth;
    if (bal==1||bal==0||bal==-1)
    {
        *count+=1;
    }
    printf("%d   ->  %d\n",head->data,bal);
    balancedfactor(head->left,count);
    balancedfactor(head->right,count);
}
int main()
{
    //QUESTIONA
    printf("QA\n");
    struct bstnode *root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 12);
    root = insert(root, 8);
    print_tree(root);
    int num=12;
    //QUESTIONB
    printf("\n\n");
    printf("QB\n");
    delete_bst(root, 5);
    print_tree(root);
    num--;
    //QUESTIONC
    printf("\n\n");
    printf("QC\n");
    printf("NODE->balancedfactor\n");
    int count=0;
    balancedfactor(root,&count);
    if (count==num)
    {
        printf("Tree is Balanced\n");
    }
    else{
        printf("Tree is not Balanced\n");
    }
    
}