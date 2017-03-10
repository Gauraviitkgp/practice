#include <stdio.h>
#include <string.h>

void remov(char str[],char x)
{
    int i=0,j;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]==x)
            {
             for(j=i;j<strlen(str);j++)
                    str[j]=str[j+1];
             i--;
            }
    }
}


int main()
{
    int i;
    char str[1000],x;
    gets(str);
    x=getchar();

    remov(str,x);
    printf("%s",str);
}
