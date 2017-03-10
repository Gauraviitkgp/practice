#include<stdio.h>
int main()
{
    char str1[]="Pineapple",str2[12];
    int i=0,j=0;
    for(i=0;i<11;i++)
        str2[i]=' ';
    i=0;
    while(str1[i]!='\0')
    {
        if(i%2==0)
            str2[j]=str1[i];
        i++;
        j++;
    }
    str2[j]='\0';
    printf("\n %d %d %s\n",i,j,str2);
    puts(str2);
    return 0;
}
