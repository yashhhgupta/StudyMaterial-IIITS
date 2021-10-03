/*Write program, which reads a, b, and c. Let ax + by + c = 0 be equation of a line. The program
outputs the slope. Input 3 5 8 output −0.6
*/
#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c,s,slope;
	printf("enter numbers\n");
	scanf("%f\n%f\n%f",&a, &b, &c);
	printf("your line is %.1fx + %.1fy + %.1f\n",a,b,c); 
	slope= -a/b;
	printf("slope=%.2f", slope);
	return 0;
}
