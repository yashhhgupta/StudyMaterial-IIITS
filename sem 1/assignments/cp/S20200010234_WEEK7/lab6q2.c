#include <stdio.h>
int main()
{
    int n;
    printf("enter a number\n");
    scanf("%d",&n);
    printf("fators=");
    for (int i = 2; i < n; i++)
    {
        if (n%i==0)
        {
            printf("%d ",i);
        }
        
    }
    return 0;
    
}