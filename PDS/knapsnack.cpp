#include <iostream>
#include <stdio.h>
#include <string.h>
#include <new>


using namespace::std;

int max(int a,int b)
{
  if(a>b)
    return a;
  else
    return b;
}

int knapsnack(int Wt[],int Vl[],int n,int W)
{
  static int i=0;
  if(n==0&&Wt[n]>W)
    return 0;
  else if (n==0&&Wt[n]<W)
    {cout<<i++<<"randva\n";return Vl[0];}
  else if(Wt[n-1]>W)
    {cout<<i++ <<"randi\n";return knapsnack(Wt,Vl,n-1,W);}
  else
    {cout<<i++<<"chod\n";return max(Vl[n-1]+knapsnack(Wt,Vl,n-1,W-Wt[n-1]),knapsnack(Wt,Vl,n-1,W));}
}



int main()
{
  int *Wt,*Vl,n,W,i,j;


  cout<<"Enter number of weights\n"; cin>>n;
  Wt=new int[n];Vl=new int[n];
  cout<<"Enter the weights\n";
  for(i=0;i<n;i++)
    cin>>Wt[i];

  cout<<"Enter the values\n";
  for(i=0;i<n;i++)
    cin>>Vl[i];

  cout<<"Enter max weight";
    cin>>W;

  cout<<knapsnack(Wt,Vl,n,W)<<":knapsnack\n";
}
