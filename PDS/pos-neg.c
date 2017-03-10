#include <stdio.h>

int main()
{
    int p=0,n=0;
    int x;
    while(1)
    {
        scanf("%d",&x);
        if(x<0)
            n++;
        if(x>0)
            p++;
        if(x==0)
            break;
    }
    printf("%d %d",n,p);
}
