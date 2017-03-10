#include <stdio.h>
float exp(int i)
{
    int j;
    float pro=1.0;
    for(j=1;j<=i;j++)
    {
        pro=j*pro;
    }
    pro=(1/pro);
    return pro;
}


int main()
{
    float sum=exp(1),diff=4242;
    int i=2;


    while(diff>0.00001)
    {
       sum += exp(i);
       diff = exp(i-1)-exp(i);
       i++;
    }
    printf("%f ", sum);
}
