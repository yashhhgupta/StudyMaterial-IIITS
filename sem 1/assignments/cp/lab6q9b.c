#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[20];
    printf("PROGRAM TO FIND LENGTH OF STRING\n");
    printf("Enter the string : h\n");
    scanf("%[^\n]%*c", str);
    int i=strlen(str);
    printf("The length of string is %d",i);
    return 0;
}