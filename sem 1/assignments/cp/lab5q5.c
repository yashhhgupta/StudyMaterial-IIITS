//Uppercase, Lowercase, Special Character, or Digit

#include <stdio.h>

int main()
{
    char ch = 'a';
    printf("enter a character\n");
    scanf("%c", &ch);

    if (ch >= 'a' && ch <= 'z')
    {
        printf("character is an alphabet");
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        printf("character is alpbhabet");
    }
    else if (ch >= '0' && ch <= '9')
    {
        printf("character is a digit");
    }
    else
    {
        printf("character is character");
    }

    return 0;
}
