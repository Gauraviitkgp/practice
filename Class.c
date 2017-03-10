#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
typedef struct{
    int roll;
    char name[20];
    int marks;
}Class;

int compare(char a[],char b[], int i)
{
    int j;
    if(a[i]>b[i])
        return 1;
    if(a[i]<b[i])
        return -1;
    if(a[i]==b[i])
    {
        for(j=1;a[j]!='\0'&& b[j]!='\0';j++)
            if (a[j]!=b[j])
                return (a,b,j);
    }

}

void sort(Class a[])
{
    int k,j,pos;
    Class temp;
    for (k=0; k<10; k++)
    {
        pos = k;
        for (j=k+1; j<10; j++)
        {
            if (compare(a[j].name , a[pos].name,0)==-1)
                pos = j;
        }
        if (compare(a[pos].name,a[k].name,0)==-1)
        {
            temp = a[k];
            a[k] = a[pos];
            a[pos] = temp;
        }
    }
}

int main()
{
    Class a[10];
    int i;

    for(i=0;i<10;i++)
        a[i].roll=400+i;
    srand((unsigned)time(NULL));
    for(i=0;i<10;i++)
        a[i].marks= 1+(rand()%100);
    strncpy (a[0].name,"Gaurav",19);
    strncpy (a[1].name,"Krutarth",19);
    strncpy (a[2].name , "Viraj",19);
    strncpy (a[3].name , "Rustom",19);
    strncpy (a[4].name , "Sanskar",19);
0    strncpy (a[5].name , "Bagate", 19);
    strncpy (a[6].name , "Prashanthi", 19);
    strncpy (a[7].name , "Asmit", 19);
    strncpy (a[8].name , "Mayank", 19);
    strncpy (a[9].name , "Krishna", 19);

    sort(a);
    for(i=0;i<10;i++)
        printf("%d\t %s   \t %d\n",a[i].roll, a[i].name,a[i].marks);
}
