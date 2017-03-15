#include <stdio.h>
#include <time.h>
int main()
{
    clock_t t;
    int f;
    t = clock();
    int sum=0,i=0,a;
    while(1)
    {
        scanf("%d",&a);
        if(a==-1)
            break;
        sum +=a;
        i++;
    }
    printf("%f\n",(float)(sum/i));
    t=clock() -t;
    printf("%d\n",t);
}
