#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count(char word[],int n)
{
    int i,coun=0;
    for(i=0;i<n;i++)
    {
        if(word[i]==32)
        {
            if((word[i+1]>=65 && word[i+1]<=90)||(word[i+1]>=97 && word[i+1]<=122))
                {
                    coun++;
                    printf("%c",word[i+1]);
                }
        }
    }
    return coun;
}



int main()
{
    FILE *p1,*p2;
    p1=fopen("S.txt","r");

    int n,a;
    /*for(n=0;(a=getw(p1))!=EOF;n++);
    printf("%d",n);*/
    char word[85];
    /*word =(char *) malloc(sizeof(char)*n+1);*/

    n=85;
    fgets(word,n,p1);

    int total;
    total = count(word,n);

    p2=fopen("Result.txt","w");
    fprintf(p2,"%d",total);


}
