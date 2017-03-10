#include <stdio.h>
#include <string.h>

int main()
{
    char a[1000],b[]="the";
    gets(a);
    int i,count=0;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i-1]==32)
            if(a[i]==b[0])
            {
                if(a[i+1]==b[1])
                {
                    if(a[i+2]==b[2])
                        count++;
                }

            }

    }
    printf("%d", count);

}
