#include <stdio.h>

int main()
{
    int sum=0,i=0,a;
    while(1)
    {
        scanf("%d",&a);
        if(a==-1)
            break;
        sum +=a;
        i++;
    }
    printf("%f",(float)(sum/i));
}
