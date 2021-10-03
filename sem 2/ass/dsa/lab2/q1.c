#include <stdio.h>
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
}