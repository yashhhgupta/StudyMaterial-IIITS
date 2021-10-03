#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, D, x, y, A, B;

    printf("enter the quadratic equation in the format ax^2+bx+c:\n");
    scanf("%f", &a);

    scanf("%f", &b);

    scanf("%f", &c);

    printf("your quadratic equation is %.1fx^2+%.1fx+%.1f\n", a, b, c);

    D = b * b - 4 * a * c;

    if (D > 0)
    {

        x = (-b + sqrt(D)) / (2 * a);
        y = (-b - sqrt(D)) / (2 * a);

        printf("roots of the function are:\n%.2f\n%.2f", x, y);
    }

    else if (D == 0)
    {
        x = y = (-b) / (2 * a);
        printf("roots of the function are:\n%.2f\n%.2f", x, y);
    }

    else if (D < 0)
    {
        A = -b / (2 * a);
        B = (4 * a * c - b * b) / 2 * a;
        printf("the roots are imaginary= %.2f+i%.2f and %.2f-i%.2f", A, B, A, B);
    }

    return 0;
}
