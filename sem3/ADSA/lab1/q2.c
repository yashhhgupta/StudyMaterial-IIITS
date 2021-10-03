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
int main(){
    char a[][10]={"abcd","abdc","adcb","acbd","acdb","adbc"};
    printf("unsorted array of strings:-\n");
    for (int i = 0; i < 6; i++)
    {

        printf("%s\n",a[i]);
    }
    insertionsort(a,6);
    printf("sorted array of strings:-\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%s\n",a[i]);
    }
    
}