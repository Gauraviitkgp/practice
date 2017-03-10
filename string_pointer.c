#include <stdio.h>
#include <string.h>

int main()
{
    char *name;
    name = "Gaurav";

    char nam[10];
    strncpy(nam,"Gaurav",7);
    printf("%s %s",name,nam);
}
