#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100];
    char str2[100];
    char str3[100];
    int result;
    printf("Enter a string\n");
    scanf("%s", str1);
    printf("Enter another string\n");
    scanf("%s", str2);
    printf("Enter another string\n");
    scanf("%s", str3);
    result = strcmp(str1, str2);
    printf("strcmp(str1, str2) = %d\n", result);

    result = strcmp(str1, str3);
    printf("strcmp(str1, str3) = %d\n", result);

    return 0;
}