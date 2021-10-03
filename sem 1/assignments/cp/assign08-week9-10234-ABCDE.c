PROBLEM 1
/*#include <stdio.h>
#include <math.h>
#include <sys/unistd.h>
#include <stdlib.h>

int primecheck(int s){
    if(s == 1 || s == 0)return 0;
    for(int i = 2; i <= s/2; i++){
        if(s % i == 0)return 0;
    }
    return 1;
}

int primesum(long long int m){
    if(m == 0)return 0;
    int e = primecheck(m % 10);
    if(e) return (m % 10) + primesum(m / 10);
    return primesum(m / 10);
}

int main(){

    //Code for 1st Problem
    long long int num1;
    printf("Enter a large number to find the sum of prime digits: ");
    scanf("%lld", &num1);
    int ans1 = primesum(num1);
    printf("%d", ans1);
}*/
PROBLEM 2
/*#include <stdio.h>
int givedig(int n)
{
    int temp;
    int count=0;
    int i=0;
    int old=n;
    while (n!=0)
    {
        
        temp=n%10;
        if ((temp%3==0||temp==1)&&temp!=0)
        {
            count++;
        }
        
        ++i;
        n=n/10;
    }
    if (count==i)
    {
        return old;
    }
    else
    {
        return 0;
    }
    

    
    
}
void print(int n)
{
    if (n==0)
    {
        
    }
    

    else 
    {
        if(givedig(n)!=0){
        printf("%d,",givedig(n));}
        return print(n-1);
    }
    
}
int check(int n,int sum)
{
    
    if (n==0)
    {
        return sum;
    }
    else
    {
        sum=sum+givedig(n);
        return check(n-1,sum);
    }
    
    
}
int main()
{
    int n;
    int sum=0;
    scanf("%d",&n);
    print(n);
    printf("\n");
    printf("%d",check(n,sum));
    return 0;
}*/
PROBLEM 3
/*#include <stdio.h>
#include <math.h>
#include <sys/unistd.h>
#include <stdlib.h>
#include <time.h>

void compare(char arr[], int i, int k, int lindex, char maxrepstr[], int maxrep, int krep){
    char s[k];
    int ref1 = i, rep = 0;
    for(int j = 0; j < k; j++){
        s[j] = arr[ref1];
        ref1++;
    }
    ref1 = i;
    for(int j = 0; j < 28; j++){
        int check = 1;
        for(int m = 0; m < k; m++){
            if(s[m] != arr[ref1])check = 0;
            ref1++;
        }
        if(check)rep++;
    }
    if(rep > maxrep){
        maxrepstr = s;
        lindex = i;
        maxrep = rep;
    }
    if(i == 30 - k){
        if(maxrep > krep){
            krep = maxrep;
            for(int j = 0; j < k; j++){
                printf("%c", maxrepstr[j]);
            }
            printf(" is the string with length %d that repeats maximum times i.e %d more times", k, krep-1);
            printf("\nIndex of starting element of the maximum repeated string is %d\n", lindex);
        }
        if(k == 5)return;
        else return compare(arr, 0, k+1,0 , "     ", 0, krep);
    }
    return compare(arr, i+1, k, lindex, maxrepstr, maxrep, krep);
}


int main(){

   //Code for 3rd Problem
    char arr[30] = {'a', 'c', 'b', 'a', 'a', 'c', 'd', 'e', 'c', 'e', 'e', 'f', 'd', 'a', 'c', 'a', 'd', 'e', 'c', 'a', 'e', 'f', 'e', 'f', 'a', 'f', 'e', 'c', 'd', 'f'};
    compare(arr, 0, 2, 0, "     ", 0, 0);

}*/
PROBLEM 4
/*#include <stdio.h>
#include <stdlib.h>
int primefactor(int x)
{

    int d = 2, maxFact;
    while (x != 0)
    {
        if (x % d != 0)
            d = d + 1;
        else
        {
            maxFact = x;
            x = x / d;
            if (x == 1)
            {
                return maxFact;
            }
        }
    }
}
void find_primefactor(int a[],int n,int i,int max)
{
    if(i==n)
    {
        printf("Largest primefactor %d\n",max);
    }
    else
    {
        max=(max<primefactor(a[i]))?primefactor(a[i]):max;
        return find_primefactor(a,n,++i,max);
    }
}

int minodd(int a[], int n, int min_no, int i)
{

    if (i == n)
    {
        return min_no;
    }

    if (a[i] < min_no && a[i] % 2 != 0)
    {
        min_no = a[i];
    }
    return minodd(a, n, min_no, ++i);
}
int maxeven(int a[], int n, int maximum_no, int i)
{
    if (i == n)
    {
        return maximum_no;
    }

    if (a[i] > maximum_no && a[i] % 2 == 0)
    {
        maximum_no = a[i];
    }
    return maxeven(a, n, maximum_no, ++i);
}
int gcd(int n1, int n2)
{
    if (n2 == 0)
    {
        return n1;
    }
    else
    {
        return gcd(n2, n1 % n2);
    }
    return n1;
}

int main()
{
    int arr[500], n, odd_min, even_max, hcf_even_odd;
    printf("Enter no. of elements of array\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = 30 + rand() % 31;
    }
    printf("Entered array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    odd_min = minodd(arr, n, 61, 0);
    even_max = maxeven(arr, n, 0, 0);
    //hcf_even_odd=gcd(even_max,odd_max);
    printf("Max even element %d \n Min odd element %d \n ", even_max, odd_min);

    find_primefactor(arr,n,0,0);

    return 0;
}*/
PROBLEM 5
/*#include <stdio.h>
#include <math.h>
#include <sys/unistd.h>
#include <stdlib.h>

void call2(int arr[], int i){
    if(i == 18) return;
    int b[2];
    b[0] = arr[i];
    b[1] = arr[i+1];
    int s = i;
    for(int i = 0; i < 19; i++){
        if((arr[i] > b[0]) && (arr[i+1] > b[1])){
            if((arr[i] % b[0] == 0) && (arr[i+1] % b[1] == 0)){
                if((arr[i] / b[0]) == (arr[i+1] / b[1])){
                    printf("(%d %d)* %d == (%d %d)", b[0], b[1], arr[i]/b[0], arr[i], arr[i+1]);
                    printf("\n");
                }
            }
        }
    }
    return call2(arr, i+1);
}

void call3(int arr[], int i){
    if(i == 17)return;
    int b[3];
    b[0] = arr[i];
    b[1] = arr[i+1];
    b[2] = arr[i+2];
    int s = i;
    for(int i = 0; i < 18; i++){
        if((arr[i] > b[0]) && (arr[i+1] > b[1]) && (arr[i+2] > b[2])){
            if((arr[i] % b[0] == 0) && (arr[i+1] % b[1] == 0) && (arr[i+2] % b[2] == 0) ){
                if(((arr[i] / b[0]) == (arr[i+1] / b[1])) &&  ((arr[i] / b[0]) == (arr[i+2] / b[2]) )  ){
                    printf("(%d %d %d)* %d == (%d %d %d)", b[0], b[1], b[2], arr[i]/b[0], arr[i], arr[i+1], arr[i+2]);
                    printf("\n");
                }
            }
        }
    }
    return call3(arr, i+1);
}

int main(){
    int arr[20] = {2, 4, 7, 5, 1, 2, 7, 4, 4, 2, 6, 12, 21, 10, 2, 4, 4, 2, 6, 9};
    call2(arr, 0);
    printf("--------------------------------------------------------------------------\n");
    call3(arr, 0);
}*/
PROBLEM 6
/*#include <stdio.h>

int isPrime(int num)
{
    int val = 1;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            val = 0;
        }
    }
    return val;
}

int arr(int prime, int non_prime, int ind, int array2d[2][10], int array[])
{
    if (ind >= 20)
    {
        return 0;
    }
    else if (isPrime(array[ind]))
    {
        array2d[1][prime] = array[ind];
        return arr(prime + 1, non_prime, ind + 1, array2d, array);
    }
    else
    {
        array2d[0][non_prime] = array[ind];
        return arr(prime, non_prime + 1, ind + 1, array2d, array);
    }
}

void main()
{
    int array[20] = {8, 2, 3, 6, 13, 11, 21, 22, 28, 23, 12, 43, 9, 17, 25, 27, 29, 47, 10, 31};
    int array2d[2][10];
    int ind = 0;
    int prime = 0;
    int non_prime = 0;
    arr(prime, non_prime, ind, array2d, array);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", array2d[i][j]);
        }
        printf("\n");
    }
}*/