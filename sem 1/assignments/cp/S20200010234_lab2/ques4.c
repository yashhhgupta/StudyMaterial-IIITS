//Question4(find sum of an AP)
#include <stdio.h>
int main()
{
    float a, b, d, n, Sum;
    n = 100;
    printf("Please enter the first 2 integers of the arithmetic progression:\n");
    scanf("%f %f", &a, &b);
    d = b - a;
    Sum = (2 * a + (n - 1) * d) * (n / 2);
    printf("Sum of the first 100 terms of the arithmetic progression is: %f\n", Sum);
    return 0;
}