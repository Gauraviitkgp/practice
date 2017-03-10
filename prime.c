#include <stdio.h>

int prime(int n)
{
    if(n%2==0)
        return 0;

}


int main()
{
    int n,x;
    scanf(%d,&n);
    x=prime(n);
    if(x==0)
        printf("Non-Prime");
    else
        printf("Prime")
}
