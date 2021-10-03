/*Write program, which reads 4 numbers a, b, c and p. Let f (x) = ax2 + bx + c be a function.
The program outputs the value of f (p). e.g. input 4 3 -1 2, output 4(2)2 + 3(2) − 1 = 21.
*/

#include <stdio.h>
int main()
{
	float a,b,c,p,x;
	printf("enter four numbers in the order a,b,c,p\n");
	scanf("%f %f %f %f", &a,&b,&c,&p);
	printf("your equation is f(x)=%.2fx^2 + %.2fx + %.2f", a,b,c);
	x= (a*p*p) + (b*p) + c;
	printf("f(p)=%2f(%.2f)%.2f + %.2f(%.2f)+ %.2f =%.2f",a,p,p,b,p,c,x);
	return 0;
}
