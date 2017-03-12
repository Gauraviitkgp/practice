#include <stdio.h>
#include <time.h>
int main()
{
    clock_t t;
    int f;
    t = clock();
    int sum=0,i=0,a;
    printf("Enter the set of values for the sum -1 to terminate");
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
    printf("%f\n",((float)t/CLOCKS_PER_SEC));
}
