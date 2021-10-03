#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[30];
    printf("Enter the length of string \n");
    scanf("%[^\n]%*c", str);
    int i=0;
    while(str[i] != '\0')
    {
        i++;
    }
    printf("%d",i);
    return 0;
}