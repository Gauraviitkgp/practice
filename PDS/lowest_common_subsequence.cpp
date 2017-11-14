#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace::std;

int max(int a,int b)
{
  if(a>b)
    return a;
  else
    return b;
}

int LCS(char A[],char B[],int i,int j)
{
  if((i==0 || j==0) &&A[i]==B[j])
    return 1;
  else if((i==0 || j==0) &&A[i]!=B[j])
    return 0;
  else if(A[i]==B[j])
    return LCS(A,B,i-1,j-1)+1;
  else
    return max(LCS(A,B,i-1,j),LCS(A,B,i,j-1));
}



int main()
{
  char A[100],B[100];
  cout<<"Enter the string A\n"; gets(A);
  cout<<"Enter the string B\n"; gets(B);
  cout<<LCS(A,B,strlen(A)-1,strlen(B)-1)<<":LCS\n";
}
