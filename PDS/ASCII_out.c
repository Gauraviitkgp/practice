#include <stdio.h>

int main()
{
    char name[20];
    printf("Please enter your name\n");
    scanf("%s",name);

    int i;
    for(i=0;name[i]!='\0';i++)
        printf("%d",name[i]);
}
