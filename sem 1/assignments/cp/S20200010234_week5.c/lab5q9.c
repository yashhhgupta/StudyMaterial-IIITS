
#include <stdio.h>
int main()
{
    int p, c, b, m, com, percentage;
    printf("enter your marks in physics,chemisty,bio,mathsand computer respectively\n");
    scanf("%d %d %d %d %d", &p, &c, &b, &m, &com);
    percentage = (p + c + b + m + com) / 5;

    switch (percentage/10)
    {
    case 10:
        printf("your grade is A");
        break;
    case 9:
        printf("your grade is A");
        break;
    case 8:
        printf("your grade is B");
        break;
    case 7:
        printf("your grade is C");
        break;
    case 6:
        printf("your grade is D");
        break;
    case 5:
        printf("your grade is E");
        break;
    case 4:
        printf("your grade is E");
        break;
    default:
        printf("your grade is F");
    }
}
return 0;
}
