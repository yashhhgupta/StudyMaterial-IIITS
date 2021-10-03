#include <stdio.h>
#include <string.h>
void decrypt(char *ch, int *j, int *i, int t, int n, char *out)
{
    for (int p = 0; p < t; p += n)
    {
        for (int l = 0; l < n; l++)
        {
            out[l + p] = ch[j[l] + p];
        }
    }
}

void encrypt(char *ch, int *i, int *j, int t, int n, char *out)
{
    for (int p = 0; p < t; p += n)
    {
        for (int l = 0; l < n; l++)
        {
            out[l + p] = ch[j[l] + p];
        }
    }
}
void change(char *ch, int *x, int y)
{
    while ((*x) % (y) != 0)
    {
        ch[*x] = '\0';
        ++(*x);
    }
}
void make_i(int *i, int n, int l)
{
    int flag = 0;
    for (int a = 0; a < l; a++)
    {
        if (flag < n)
        {
            *(i + a) = flag;
            flag += 1;
        }
        else
        {
            flag = 0;
            *(i + a) = flag;
            flag += 1;
        }
    }
}
void make_j(int *j, int *i, int a, int b, int n, int t)
{
    for (int num = 0; num < (t); num++)
    {
        *(j + num) = (a * (*(i + num)) + b) % (n);
    }
}

void main()
{
    char ch[50], out[50];
    printf("Type a string: \n");
    scanf("%[^\n]%*c", ch);
    int a, b, n, t = strlen(ch);
    printf("Enter values of a, b and n: \n");
    scanf("%d %d %d", &a, &b, &n);
    printf("\n");
    change(ch, &t, n);
    int i[50], j[50];
    make_i(i, n, t);
    make_j(j, i, a, b, n, t);
    printf("Encrypted string is : \n");
    encrypt(ch, i, j, t, n, out);
    for (int p = 0; p < t; p++)
    {
        if (out[p] == '\0')
            printf("\\0");
        printf("%c", out[p]);
    }
    printf("\n");
    printf("Decrypted string is : \n");
    decrypt(ch, i, j, t, n, out);
    for (int p = 0; p < t; p++)
    {
        if (out[p] == '\0')
            printf("\\0");
        printf("%c", out[p]);
    }
    printf("\n");
}