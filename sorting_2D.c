#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **p;
    int n,i,j;

    printf("Enter the value of n\n");
    scanf("%d", &n);

    p=(int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++)
        p[i] = (int *)malloc(sizeof(int)*n);

    srand(400);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            p[i][j]=1+(rand()%100);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",p[i][j]);
        printf("\n");
    }

}
