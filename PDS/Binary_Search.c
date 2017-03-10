#include <stdio.h>
#include <stdlib.h>

int search(int x, int *p, int n, int l,int r)
{
    int mid=((r+l)/2);
    if(p[mid]==x)
        return mid;
    if(l==mid || r==mid)
        return -1;
    if(p[mid]<x)
        return search(x,p,n,mid,r);
    if(p[mid]>x)
        return search(x,p,n,l,mid);
}



int main()
{
    int r,n,*p,i,x;

    scanf("%d", &n);

    p = (int *)malloc(sizeof(int)*n);

    for(i=0;i<n;i++)
        scanf("%d",&p[i]);

    scanf("%d", &x);

    r=search(x,p,n,0,n-1);

    if(r==-1)
        printf("Not found");
    else
        printf("Position is %d", r+1);
}
