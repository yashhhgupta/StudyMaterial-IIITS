#include <stdio.h>
int fib_recursive(int *n)
{
    if (*n == 0 || *n == 1)
    {
        return *n;
    }
    int x1=*n-1;
    int x2=*n-2;
    return fib_recursive(&x1)+fib_recursive(&x2);
}
int main()
{   int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("%d\n",fib_recursive(&i));
    }
    return 0;
}
