#include <stdio.h>

int n,k=1;

void print_ver(int r,int *k,int a[50][50],int i);

void print_hor(int r,int a[50][50],int i)
{
    int j;
    if(i%2==0)
    {
        for(j=0;j<r;j++)
            a[n-r][j]=k++;
    }
    if(i%2==1)
    {
        for(j=r-1;j>=0;j--)
            a[r-1][j]=k++;
    }

}




int main()
{
    int a[50][50];
    int i,j;


    printf("Enter the value of n:-");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(i==4)
        {
            print_hor(n-i,a,i);
            break;
        }

    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);

        }
        printf("\n");
    }
}
