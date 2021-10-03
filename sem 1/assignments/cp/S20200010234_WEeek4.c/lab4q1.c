/*Write program,
 which reads a, b and c as sides of a triangle and prints area.
p − a)(s − b)(s − c) . [Hint: s is (a + b + c)/2] [sqrt(x) will find square root]. Input
Hint: area = s(s5 7 10 output 16.24
*/
#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c,s,area;
	printf("enter numbers\n");
	scanf("%f\n%f\n%f",&a, &b, &c);
	 
	s=(a+b+c)/2;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("area=%.2f", area);
	return 0;
}
