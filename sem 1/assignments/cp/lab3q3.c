/*Program to find the sum of last two digits.
input 13613, output 1 + 3 = 4 and input 324, output 2 + 4 = 6.
*/

#include <stdio.h>
int main()
{	
	int a,c,d;
	printf("enter a number\n");
	scanf("%d", &a);
	c=a%10;
	a=a/10;
	d=a%10;
	printf("sum of last two digit = %d", c+d);
	return 0;
}
