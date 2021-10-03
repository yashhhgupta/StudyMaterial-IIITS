//The Greatest Number Among the Given Three Number
#include<stdio.h>

int main()
{
    int a,b,c;

    printf("enter three numbers to compare\n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if (a>=b&&a>=c)
    {
        printf("%d\n",a);
    }

    else if (b>=a&&b>=c)
    {
        printf("%d\n",b);
    }

    else if (c>=b&&c>=a)
    {
        printf("%d\n",c);
    }
    

    return 0;
}
