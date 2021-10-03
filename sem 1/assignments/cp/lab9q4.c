#include <stdio.h>
void reverse(char *string){
    char *begin,*end;;
    int length=0;
    char temp;
    while(*(string+length) != '\0'){
        length++;
    }
    begin=string;
    end=string;
    for(int i=0;i<(length-1);i++){
        end++;
    }
    for(int i=0;i<length/2;i++){
        temp=*end;
        *end=*begin;
        *begin =temp;
        begin++;
        end--;
    }
}
void main(){
    int n;
    scanf("%d",&n);
    char string[n];
    gets(&string);
    reverse(&string);
    printf("%s",string);
}