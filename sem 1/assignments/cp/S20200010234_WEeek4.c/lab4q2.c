/*Write program, which reads a, b, c and d and finds distance between points (a, b) and (c, d). Input 3,
7, 11, 13 output 10.
*/#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c,d,distance;
	printf("enter numbers\n");
	
	scanf("%f\n%f\n%f\n%f",&a, &b, &c,&d);
	printf("your points are (%.2f,%.2f),(%.2f,%.2f)\n",a,b,c,d); 	
	distance=sqrt(pow(d-b,2)+pow(c-a,2));
	printf("distance=%.2f", distance);
	return 0;
}
