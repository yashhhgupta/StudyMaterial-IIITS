#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int check_string(char arr[])
{
    int j=0,temp=1,temp2=0;
    for(int i=0;i<strlen(arr);i++)
    {
        if(arr[i]=='1')
        {
            j+=1;
            if(temp==1)
            {
                temp2+=1;
                temp=0;
            }
        }
        else
        {
            temp=1;
        }
    }
    if(j==0)
    {
        return 0;
    }
    else
    {
        if(temp2==1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

}
int main(){
    printf("Q2\n");
    char arr[100]="0111110000";
    // printf("Enter string\n");
    // scanf("%s",&arr);
    
    printf("%d \n",check_string(arr));
    return 0;
}