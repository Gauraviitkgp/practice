#include <stdio.h>
#include <iostream>
#include <new>

using namespace::std;

int n;
int *visit= new int[n];int *distanc = new int[n];int *stac= new int[n+1];


void init()
{
  int i;
  for(i=0;i<n;i++)
    {
      visit[i]=0;
      distanc[i]=10000;
      stac[i]=-1;
    }
  stac[n]=-1;
}

void print(int **p)
{
  cout<<endl;
  int i,j;
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	cout<<p[i][j]<<" ";
      cout<<endl;
    }
}

void push(int node)
{
  static int i=0;
  stac[i++]=node;
}

void prints()
{
  int i=0;
  while(1)
    {
      if(stac[i]!=-1)
	cout<<stac[i++]<<" ";
      else
	{
	  cout<<endl;
	  break;
	}
    }
}

void printd()
{
  int i;
  for(i=0;i<n;i++)
      cout<<visit[i]<<" ";
  cout<<endl;

  for(i=0;i<n;i++)
    cout<<distanc[i]<<" ";
  cout<<endl;
}

  
void dijstra(int **p,int node,int initial)
{
  int i;
  if(visit[node]!=1)
    {
      push(node);
      visit[node]=1;
    }
  
  for(i=0;i<n;i++)
      if(p[node][i]!=0)
	if((p[node][i]+initial)<distanc[i])
	      distanc[i]=p[node][i]+initial;
  prints();
  cout<<endl;
  int min=20000,c=-2;
  for(i=0;i<n;i++)
    {
      if(visit[i]==0 && distanc[i]<min)
	{
	  printd();
	  min=distanc[i];
	  c=i;
	}
    }
  //cout<<" C:"<<c<<endl;
  if(c!=-2)
    dijstra(p,c,min);
}

void printda(int start)
{
  int i;
  for(i=0;i<n;i++)
      cout<<visit[i]<<" ";
  cout<<endl;

  for(i=0;i<n;i++)
    if(i==start)
      cout<<"0 ";
    else
      cout<<distanc[i]<<" ";
  cout<<endl;
}


int main()
{
  int **p,i,x,j;

  cout<<"Enter the number of elements:";
  cin>>n;

  p=new int*[n];
  for(i=0;i<n;i++)
    p[i]=new int[n];

  
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  if(i==j)
	    p[i][j]=0;
	  else
	    {
	      cout<<"Enter the  Weight between "<<i<<" and "<<j<<":";
	      cin>>x;
	      p[i][j]=x;
	    }
	}
    }
  int start=0;
  print(p);
  init();
  dijstra(p,start,0);
  printda(start);
}
