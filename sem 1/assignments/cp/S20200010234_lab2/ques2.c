//Question 2(find addition,subtraction,multiplication,division,modulus of given numbers)
#include <stdio.h>
int main()
{
    int a, b;
    printf("enter first number\n");
    scanf("%d", &a);
    printf("enter second number\n");
    scanf("%d", &b);

    printf("a)addition of two numbers is:%d\n", a + b);
    printf("b)subtraction of two numbers is:%d\n", a - b);
    printf("c)multiplication of two numbers is:%d\n", a * b);
    printf("d)division of two numbers is:%f\n", a / b);
    printf("e)modulus of two numbers is:%d\n", a % b);
    return 0;
}
