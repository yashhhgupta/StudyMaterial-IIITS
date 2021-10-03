#include <stdio.h>
int main()
{
    int n;
    int new=0;
    int rem,oldn;
    printf("enter a number\n");
    scanf("%d",&n);
    oldn=n;
    while (n!=0)
    {
        rem=n%10;
        new=new*10+rem;
        n=n/10;
        
    }
    if (new==oldn)
    {
        printf("it is palindrome");
    }
    else
    {
        printf("it is not palindrome");
    }
    return 0;

}