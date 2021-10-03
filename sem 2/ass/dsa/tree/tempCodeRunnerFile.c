#include <stdio.h>
#include <stdlib.h>

struct bstnode{
    int data;
    struct bstnode *left;
    struct bstnode *right;
};

struct bstnode *getnewnode(int data){
    struct bstnode *newnode = (struct bstnode*) malloc(sizeof(struct bstnode));
    newnode->data = data;
    newnode->left =NULL;
    newnode->right =NULL;
    return newnode;
}
struct bstnode *insert(struct bstnode *root ,int data){
    if (root==NULL)
    {
        root=getnewnode(data);
        
    }
    else if (data<=root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}

int main()
{
    struct bstnode *root=NULL;
    root =insert(root,15);
    root =insert(root,10);
    root =insert(root,25);

}