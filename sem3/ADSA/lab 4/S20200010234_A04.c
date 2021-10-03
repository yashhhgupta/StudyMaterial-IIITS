#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void print_tree(struct node *root);
int Bst_height(struct node *head)
{

    if (head == NULL)
    {
        return -1;
    }
    else
    {
        return (max(Bst_height(head->left), Bst_height(head->right)) + 1);
    }
}
int balancedfactor(struct node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int lefth = Bst_height(head->left);
    int righth = Bst_height(head->right);
    return lefth - righth;
}
struct node *getnewnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node *LLrotate(struct node *p)
{
    struct node *pl = p->left;
    struct node *plr = pl->right;
    pl->right = p;
    p->left = plr;
    return pl;
}
struct node *RRrotate(struct node *p)
{
    struct node *pr = p->right;
    struct node *prl = pr->left;
    pr->left = p;
    p->right = prl;
    return pr;
}
struct node *LRrotate(struct node *p)
{
    struct node *pl = p->left;
    struct node *plr = pl->right;
    pl->right = plr->left;
    p->left = plr->right;
    plr->right = p;
    plr->left = pl;
    return plr;
}
struct node *RLrotate(struct node *p)
{
    struct node *pr = p->right;
    struct node *prl = pr->left;
    pr->left = prl->right;
    p->right = prl->left;
    prl->right = pr;
    prl->left = p;
    return prl;
}
struct node *insert(struct node *root, int data)
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

    if (balancedfactor(root) == 2 && balancedfactor(root->left) == 1)
    {
        return LLrotate(root);
    }
    else if (balancedfactor(root) == 2 && balancedfactor(root->left) == -1)
    {
        return LRrotate(root);
    }
    else if (balancedfactor(root) == -2 && balancedfactor(root->right) == -1)
    {
        return RRrotate(root);
    }
    else if (balancedfactor(root) == -2 && balancedfactor(root->right) == 1)
    {
        return RLrotate(root);
    }

    return root;
}
struct node *FindMin(struct node *root)
{
    struct node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
struct node *delete_bst(struct node *root, int data)
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
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            struct node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = delete_bst(root->right, root->data);
        }
    }
    if (root == NULL)
    {
        return root;
    }
    if (balancedfactor(root) == 2 && balancedfactor(root->left) == 1)
    {
        return LLrotate(root);
    }
    else if (balancedfactor(root) == 2 && balancedfactor(root->left) == -1)
    {
        return LRrotate(root);
    }
    else if (balancedfactor(root) == -2 && balancedfactor(root->right) == -1)
    {
        return RRrotate(root);
    }
    else if (balancedfactor(root) == -2 && balancedfactor(root->right) == 1)
    {
        return RLrotate(root);
    }
    return root;
}
void print_tree(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    print_tree(root);
    printf("\n");
    root = delete_bst(root, 40);
    print_tree(root);
}