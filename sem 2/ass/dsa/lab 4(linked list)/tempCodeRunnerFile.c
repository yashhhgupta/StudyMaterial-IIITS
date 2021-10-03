int main()
{
    printf("enter your sorted list\n");
    struct node *a;
    a = create_list(a);
    printf("enter the number you want to add:\n");
    int x;
    scanf("%d", &x);
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    a = insert_sorted(a, n);
    print(a);
}