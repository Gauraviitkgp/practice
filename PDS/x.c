#include <stdio.h>

int main()
{
    int *p,*q;
    int a=10,b=5;
    p = &a; q=&b;
    q=p+1;
    printf("%f\n",(float *)q-(float *)p);
}
