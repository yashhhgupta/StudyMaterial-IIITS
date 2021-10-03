//Write program to print the second last digit. input 23617, output 1.

#include <stdio.h>
int main()
{
	int a,b;
	printf("enter a number\n");
	scanf("%d" , &a);
	a=a/10;
	b=a%10;
	printf("second last digit=%d", b);
	return 0;	
}

