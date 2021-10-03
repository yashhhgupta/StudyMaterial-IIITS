#include<stdio.h>
void cycle(int *x,int *y,int *z)
{
    int t1,t2,t3;
    t1=*x;
    t2=*y;
    t3=*z;
    *x=t3;
    *y=t1;
    *z=t2;

}
void acycle(int *x,int *y,int *z)
{
    int t1,t2,t3;
    t1=*x;
    t2=*y;
    t3=*z;
    *x=t2;
    *y=t3;
    *z=t1;

}
void main()
{
int a = 1, b =2, c =3;
cycle(&a, &b, &c);
printf("%d %d %d\n",a,b,c);
//now the value of a=3, b=1, c=2
cycle (&a, &b, &c);
printf("%d %d %d\n",a,b,c);

//now the value of a =2, b=3, c=1
acycle (&a, &b, &c);
printf("%d %d %d\n",a,b,c);

}