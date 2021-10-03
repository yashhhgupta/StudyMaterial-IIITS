#include <stdio.h>
#include <stdlib.h>

struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
};

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
struct bstnode *construct_bst(int arr[], int n, struct bstnode *root)
{
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}
struct bstnode *FindMin(struct bstnode *root)
{
    struct bstnode *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
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
            struct bstnode *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = delete_bst(root->right, data);
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
void print_tree(struct bstnode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);

        print_tree(root->left);
        print_tree(root->right);
    }
}
int main()
{
    //question1
    printf("Q1\n");
    struct bstnode *root = NULL;
    int arr[] = {1, 44, 55, 27, 3, 22, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    root = construct_bst(arr, n, root);
    print_tree(root);

    //question2
    printf("\n\n\n\n-------------------------\n");
    printf("Q2\n");
    delete_bst(root,22);
    print_tree(root);

    //question3
    printf("\n\n\n\n-------------------------\n");
    printf("Q3\n");
    printf("height of tree = %d",Bst_height(root));
    return 0;
}