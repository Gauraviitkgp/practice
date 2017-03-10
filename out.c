#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *p1;
    p1 = fopen("S.txt","r");

    char a[1000];
    fscanf(p1,"%s",a);
    printf("%s",a);

    fclose(p1);
}
