#include <stdio.h>

float value(float x,float m,float c)
{
    return (m*x+c);
}


float area(float m, float c,float a,float b)
{
    int i;
    float w=((b-a)/10000),sum=0,lower;
    for(lower=a;lower<=b-w;lower+=w)
        sum += (0.5*w*(value(lower,m,c)+value((lower+w),m,c)));
    return sum;
}



int main()
{
    float m,c,a,b,x;

    printf("Enter m and c\n");
    scanf("%f%f",&m,&c);

    printf("Enter the limits\n");
    scanf("%f%f",&a,&b);

    x=area(m,c,a,b);
    printf("%5.2f",x);
    getch();
}
