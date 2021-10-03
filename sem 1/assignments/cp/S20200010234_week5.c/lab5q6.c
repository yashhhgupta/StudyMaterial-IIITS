//Uppercase, Lowercase, Special Character, or Digit

#include <stdio.h>

int main()
{
    char ch = 'a';
    printf("enter a character\n");
    scanf("%c", &ch);

    if (ch >= 'a' && ch <= 'z')
    {
        printf("character is an lowercase");
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        printf("character is Uppercase");
    }
    
    else
    {
        printf("enter an alphabet");
    }

    return 0;
}
