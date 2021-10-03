//Question 3(find hypotenuse of right triangle)
#include <stdio.h>
#include <math.h>
int main()
{

    float h, b, hypo;
    printf("enter height of rectangle\n");
    scanf("%f", &h);
    printf("enter breadth of rectangle\n");
    scanf("%f", &b);
    hypo = sqrt((h * h) + (b * b));
    printf("hypotenuse of right angled triangle= %f", hypo);

    return 0;
}