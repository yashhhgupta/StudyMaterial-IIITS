/*#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void findnum(int *arr, int* n, int* num,int* count){
    int temp = 0;
    int i = 0;
    count+=2;
    for(i = 0; i < *n; i++){
        if(arr[i] == *num){
            count += 4;
            temp = 1;
            printf("number is found at index %d\n", i);
            break;
        }
        else
        count += 3;
    }
    if(temp == 0){
        printf("number is not found\n");
        count += 1;
    }
    
}

int main(){
    srand((unsigned int) time(NULL));
    int count=0;
    int n;
    count++;
    printf("Enter the value of n \n");
    scanf("%d", &n);
    int arr[n];
    count++;
    for(int i = 0; i < n; i++){
        arr[i] = rand() %n + 1;
        count+=3;
    }
    int num;
    count++;
    printf("Enter the number you want to search\n");
    scanf("%d", &num);
    findnum(arr, &n, &num,&count);
    printf("number of primitive operations used is %d\n", count);
    return 0;
}*/

/*#include <stdio.h>
#include <math.h>
int prime(int *n)
{
    int temp = 0;
    for (int i = 2; i <= sqrt(*n); i++)
    {
        if (*n % i == 0)
        {
            temp = 1;
            break;
        }
    }
    return temp;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (prime(&n) == 1)
    {
        printf("NON PRIME\n");
    }
    else
    {
        printf("PRIME\n");
    }
    printf("The worst-case running time of my program is O(sqrt(n))\n");
    return 0;
}*/
/*#include <stdio.h>
int fib_recursive(int *n)
{
    if (*n == 0 || *n == 1)
    {
        return *n;
    }
    int x1=*n-1;
    int x2=*n-2;
    return fib_recursive(&x1)+fib_recursive(&x2);
}
int main()
{   int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("%d\n",fib_recursive(&i));
    }
    return 0;
}
/*The time complexity of the function can be calculated using recursive tree

        1=2^0           n
        2=2^1       (n-1)   (n-1)
        4=2^2   (n-2)(n-3)  (n-3)(n-4)
        2&i for ith level

    hence total time would be sum of all the levels 2^0+2^1+2^2+......+2^(n-1)=2^n
    Therefore time complexity is O(2^N)*/

    
*/