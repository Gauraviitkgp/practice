#include <stdio.h>

int sum(int ISBN)
{
    int add=0,i=9;
    while(ISBN>0)
    {
        ISBN /=10;
        add += ISBN%10*i;
        i--;
    }
    return add;
}



int main()
{
    int ISBN, check,i;

    scanf("%d", &ISBN);

    if(ISBN%10==(sum(ISBN)%11))
        printf("Valid ISBN");
    else
        printf("Invalid ISBN");
}
