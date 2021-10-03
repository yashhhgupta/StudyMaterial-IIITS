#include <stdio.h>
void summation(int *arr,int *sum,int *n){
    int s=*sum;
    for(int i=0;i<*n;i++){
        s += *(arr+i);
    }
    *sum = s;
}
void main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sum=0;
    summation(arr,&sum,&n);
    printf("%d",sum);
}