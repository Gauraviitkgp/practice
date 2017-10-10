#include <stdio.h>
#include <iostream>
#include <new>

using namespace::std;
typedef struct node{
  int value;
  int number;
  struct node *next=NULL;
}Node;

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

void dist(Node A,int initial)
{
  if((A.value!=0) && (A.value+initial < distanc[A.number]))
    distanc[A.number]=A.value+initial;
  if(A.next!=NULL)
    dist(*(A.next),initial);
}

  
int mst(Node A,int* p)
{
  int i;
  
  if(visit[A.number]!=1)
    {
      push(A.number);
      visit[A.number]=1;
    }
  dist(A,*p);

  prints();
  cout<<endl;
  printd();
  int min=20000,c=-2;
  for(i=0;i<n;i++)
    {
      if(visit[i]==0 && distanc[i]<min)
	{
	  min=distanc[i];
	  c=i;
	}
    }
  *p=min;
  //cout<<" C:"<<c<<endl;
  return c;
}

void makelist(int **p,int n)
{
  int i,j;
  Node* A=new Node[n];
  Node* B;
  cout<<endl;
  for(i=0;i<n;i++)
    {
      B=&A[i];
      A[i].value=0;//value is the weight between two nodes
      A[i].number=i;//Number is the index of node
      cout<<i<<" ";
      for(j=0;j<n;j++)
	{
	  if(p[i][j]!=0)
	    {
	      Node* temp=new Node;
	      B->next=temp;
	      B=temp;
	      B->number=j;
	      B->value=p[i][j];
	      B->next=NULL;
	      cout<<"(Node:"<<j<<" Weight:"<<B->value<<") ";
	    }
	}
      cout<<endl;
    }
  int c;
  int initial=0;
  int *q=&initial;
  while(1)
    {
      c=mst(A[0],q);
      if(c!=-2)
	mst(A[c],q);
      else
	break;
    }
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

  init();
  makelist(p,n);
}
