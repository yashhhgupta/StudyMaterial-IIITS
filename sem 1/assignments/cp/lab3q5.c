/*Read two numbers. Find their product after exchanging last digits. Input 4270 and 153
output 640950 (4273 × 150). Input 348 and 31 output 12958 (341 × 38).
*/
#include <stdio.h>
int main()
{
	int a,b,x,y,newa,newb;
	printf("enter two numbers\n");
	scanf("%d %d",&a, &b);
	x=a%10;
	y=b%10;
	newa= (a/10)*10+y;
	newb= (b/10)*10+x;
	printf("%d",newa*newb);
	return 0; 
}
