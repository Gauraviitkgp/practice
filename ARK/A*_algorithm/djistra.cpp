#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace::std;



void djistra ( int A[30][30],int l,int b)
{
  int i,j,k,s,t,a,b,c;
  int vis[100],cost[100];
  for(i=0;i<l;i++)
  {
    for(j=0;j<b;j++)
    if(A[i][j]==1)
    break;

    if(A[i][j]==1)
    break;
  }
  int i1=i;
  int j1=j;

  for(i=0;i<100;i++)
  {
    cost[i]=100000;
    vis[i]=0;
  }

  cost[0]=0;
  vis[0]=1;

  c=0

  for(i=0;i<l;i++)
  {
    for(j=0;j<b;j++)
    {
      if(A[i][j]!=0)
      {
        for(k=0;k<100;k++)
        {
          if(A[i][j]==vis[k])
          {
            for(s=-1;s+i>0 && s+i<l;s++)
            {
              for(t=-1;t+j>0 && t+j<b;t++ )
              {
                if(A[s+i][t+j]!=0)
                {
                  for(k=0;k<100;k++)
                  {
                    if(A[s+i][t+j]!=vis[k])
                      vis[c++]=A[s+i][t+j];
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}




int main()
{
  int l,b;
  cin>>l>>b;

  int A[30][30];
  int i,j;

  for(i=0;i<l;i++)
    for(j=0;j<b;j++)
      cin>>A[i][j];

  for(i=0;i<l;i++)
  {
    for(j=0;j<b;j++)
      cout<<A[i][j];
    cout<<endl;
  }

  djistra(A,l,b);

}
