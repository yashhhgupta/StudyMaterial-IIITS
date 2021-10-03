//Write program, which reads as input sides of a rectangle and prints its area.
#include <stdio.h>
int main()
{	
	float a,b,area;
	printf("enter sides of rectangle\n");
	scanf("%f %f",&a,&b);
	area= a*b;
	printf("area of rectagle of sides= %.3f", area);
	return 0;
	 
}
