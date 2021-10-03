/*Write program, which reads a, b, c, d and e and prints the distance between point (a, b) and line
cx + dy + e = 0. [Hint: (ac + bd + e)/(c2 + d2 )1/2 .] Input 6 7 3 4 2 output 9.6
*/
#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c,d,e,distance;
	printf("enter numbers\n");
	
	scanf("%f\n%f\n%f\n%f\n%f",&a, &b, &c,&d,&e);
	printf("your points is (%.2f,%.2f)\n)",a,b);
	printf("your line is %.1fx + %.1fy + %.1f\n",c,d,e); 	
	distance=(a*c+b*d+e)/sqrt(c*c+d*d);
	printf("distance=%.2f", distance);
	return 0;
}
