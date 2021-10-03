#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3][3];
    int b[3][3];
    printf("PROGRAM TO MULTIPLY TWO MATRIX\n");
    printf("Input elements of matrix 1 \n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Input elements of matrix 2 \n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    int mul[3][3];
    for(int i=0;i<3;i++)
    {
       for(int j=0;j<3;j++)
       {
        mul[i][j]=0;
        for(int k=0;k<3;k++)
         {
           mul[i][j]+=a[i][k]*b[k][j];
         }
       }
    }
    printf("Printing the multiplied matrix \n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d   ", mul[i][j]);
        }
        printf("\n");
    }
    return 0;
}