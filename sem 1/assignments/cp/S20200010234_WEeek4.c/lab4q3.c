/*Write program, which reads 6 numbers a, b, c, d, e and f . The program outputs the area of the
triangle whose end points are (a, b), (c, d) and (e, f ). [Hint: use above two questions]. Input 7 3 11 3
7 6 output 6.
*/
#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c,d,e,f,distance1,distance2,distance3,s,area;
	printf("enter numbers\n");
	
	scanf("%f\n%f\n%f\n%f\n%f\n%f",&a, &b, &c,&d,&e,&f);
	printf("your points are (%.2f,%.2f),(%.2f,%.2f,(%.2f,%.2f\n))",a,b,c,d,e,f); 	
	distance1=sqrt(pow(d-b,2)+pow(c-a,2));
	distance2=sqrt(pow(f-d,2)+pow(e-c,2));
	distance3=sqrt(pow(f-b,2)+pow(e-a,2));
	s=(distance1+distance2+distance3)/2;
	area=sqrt(s*(s-distance1)*(s-distance2)*(s-distance3));
	printf("area=%.2f", area);
	return 0;
}
