#include <stdio.h>
int main()
{
    float unit,total;
    printf("enter units\n");
    scanf("%f",&unit);
    printf("your bill for %f units is:\n",unit);
    if (unit<=50)
    {
        total=0.5*50;
    }
    else if (unit<=150&&unit>50)
    {
        total=0.75*50;
    }
    else if (unit<=250&&unit>150)
    {
        total=1.2*50;
    }
    else if (unit>250)
    {
        total=1.5*50;
    }
    printf("%.2f", total+(total*0.2));
    
}