#include <stdio.h>
#include <stdlib.h>
void sort(int p[3][3])
{
    int pos,k,j,temp;
    for (k=0; k<9; k++)
    {
        pos = k; /* assume first element is the smallest element */
        for (j=k+1; j<9; j++)
        {
            if (*(*(p+(int)(j/3))+(j%3))< *(*(p+(int)(pos/3))+(pos%3))) /* x[pos] is the smallest element as of now */
            pos = j;
        }
        if (*(*(p+(int)(pos/3))+(pos%3)) < *(*(p+(int)(k/3))+(k%3)))
        {
            temp = *(*(p+(int)(k/3))+(k%3));
           *(*(p+(int)(k/3))+(k%3)) = *(*(p+(int)(pos/3))+(pos%3));
           *(*(p+(int)(pos/3))+(pos%3)) = temp;
        }
    }
}



int main()
{
    int p[3][3];
    int n=3,i,j;

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

    sort(p);
    printf("-----------------------------------------\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",p[i][j]);
        printf("\n");
    }

}
