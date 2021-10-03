#include <stdio.h>
long int factorial(int num){
    if (num>=1)
    {
        return num*factorial(num-1);
    }
    else
    {
        return 1;
    }
    
}
void checkstrong(int num){
    long long sum,temp;
    for (int i = 1; i <= num; i++)
    {
        temp=i;
        sum=0;
        while (temp>0)
        {
            sum+=factorial(temp%10);
            temp=temp/10;
        }
        if(sum==i){
            printf("%d ",i);
        }
        
    }
    
}
int main()
{
    int num;
    
    printf("enter a number\n");
    scanf("%d",&num);
    checkstrong(num);
    
    return 0;
}