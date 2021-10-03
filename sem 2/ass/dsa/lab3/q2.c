#include <stdio.h>
#include <stdlib.h>
int main()
{
    int array[10];
    int n = sizeof(array) / sizeof(int);
    int j = 3;
    for (int i = 0; i < n; i++)
    {
        if (i != j)
        {
            array[i] = rand();
        }
    }
    int num, x;
    printf("enter the number and position where you want to insert\n");
    scanf("%d %d", &num, &x);
    if (x == j)
    {
        array[j] = num;
    }
    else if (x < j)
    {
        for (int i = x; i < j; i++)
        {
            array[i] = array[i + 1];
        }
        array[x] = num;
    }
    else if (x > j)
    {
        for (int i = j; i < x; i++)
        {
            array[i] = array[i + 1];
        }
        array[x] = num;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}
/* The Modified Insert algorithm consists of three cases:-
       (1)  When the location where element has to be inserted is same as the location vacant space in array;- In this case the elemnt will be inserted in the vacant location without any issues.
       (2)  When the location where element has to be inserted is ahead of the location vacant space in array:- In this case firstly the elements between the location entered and the vacant space are shifted a location before and after that the element is inserted in the vacant space generated due to shifting.
       (3) When the location where element has to be inserted is before the location vacant space in the array:- In this case firstly the elements between the location entered and the vacant space are shifted a location ahead and after that the elements is inserted in the vacant space generated due to shifting at the entered location.
*/