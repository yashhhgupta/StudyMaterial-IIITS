#include <stdio.h>
#include <string.h>
void insertionsort(char arr[][10],int n){
    int j;
    char key[10];
    for (int i = 1; i < n; i++)
    {
        strcpy(key,arr[i]);
        j = i - 1;
        while (j >= 0 && strcmp(arr[j],key)>0)
        {
            strcpy(arr[j + 1],arr[j]);
            j -= 1;
        }
        strcpy(arr[j + 1],key);
    }
}
void solution1(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int j = 0; j < n; j++)
    {
        scanf("%d",&arr[j]);
    }
    int temp,swap=0;
    for (int k = 0; k < n-1; k++)
    {
        for (int j = 0; j < n-1-k; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap++;
            }
            
        }
        
    }
    printf("%d\n",swap);
}
void solution2(){
    printf("Insertion sort will take minimum time.\n");
    char a[][10]={"abcd","abdc","adcb","acbd","acdb","adbc"};
    printf("unsorted array of strings:-\n");
    for (int i = 0; i < 6; i++)
    {

        printf("%s  ",a[i]);
    }
    printf("\n");
    insertionsort(a,6);
    printf("sorted array of strings:-\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%s  ",a[i]);
    }
    printf("\n");

}
int main(){
    //Question 1
    solution1();
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    //Question 2
    solution2();
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    //Question 3
    
    return 0;
    
}