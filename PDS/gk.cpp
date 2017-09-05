#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace::std;


void add_ques(FILE *fptr)
{
  cout<<"Enter 0 to terminate question asking\n";

  char str[5000];

  while(1)
  {
    cout<<"Enter the question\n";
    gets(str);
    

    if(strcmp(str,"0")==0)
      break;
    else
    {
      fputs(str,fptr);
      fprintf(fptr,"\n");

      cout<<"Enter the Answer\n";
      gets(str);
      fputs(str,fptr);
      fprintf(fptr,"\n");
    }
  }

}

int main()
{
  int a,b;
  char t;

  cout<<"Do you want to add questions or want to play (a or d)\n";

  cin>>t;
  if(t=='a')
  {
    FILE *fptr;

    fptr=fopen("gk.txt","a");
    add_ques(fptr);
    fclose(fptr);
  }
  return 0;
}
