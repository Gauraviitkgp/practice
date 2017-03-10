#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\Mahi Suryawanshi\Documents\IIT Kharagpur\Computer science\Programs\sorting.h>

int main()
{
    int n,*a,i;

    printf("Enter the value of n:-");
    scanf("%d",&n);

    a=(int *)malloc(sizeof(int)*n);

    printf("Enter the values:-\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    qck_Sort(a,0,n-1);

    print(a,n);

}
