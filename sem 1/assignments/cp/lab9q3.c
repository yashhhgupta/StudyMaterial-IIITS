#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fill(int *arr, int pt)
{
    if (pt <= 29)
    {
        if (*pt == 0)
            arr = 0;
        else if (pt == 1)
            arr = 1;
        else if (pt == 2)
            *arr = 1;
        else
        {
            *arr = *(arr - 1) + *(arr - 3);
        }
        *pt = *pt + 1;
        fill(arr + 1, pt);
    }
}

void main(){
    int a[30], index = 0;
    fill(&a[0], &index);
    printf("All elements of the array are: \n");
    for(int i = 0; i < 30; i++)printf("%d ", a[i]);
}