#include <stdio.h>
#include <math.h>

void root(float *a, float *b,float *c,float *x1, float *x2)
{
    *x1 = ((-*b+sqrt((*b)*(*b)-4*(*a)*(*c)))/(2*(*a)));
    *x2 = ((-*b-sqrt((*b)*(*b)-4*(*a)*(*c)))/(2*(*a)));

}

int main()
{
    float b,a,c,x1,x2;

    scanf("%f%f%f",&a,&b,&c);

    root(&a,&b,&c,&x1,&x2);
    printf("%5.2f %5.2f",x1,x2);
}
