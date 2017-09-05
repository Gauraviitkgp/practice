#include <stdio.h>
#include <iostream>
#include <new>

using namespace::std;
typedef struct node{
  int value;
  int number;
  struct node *next=NULL;
}Node;



void print(int **p, int n)
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

void prind(Node B)
{
  cout<<B.value<<" ";
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
      A[i].value=0;
      A[i].number=i;
      cout<<i<<" ";
      for(j=0;j<n;j++)
	{
	  if(p[i][j]!=0)
	    {
	      Node* temp=new Node;
	      (*B).next=temp;
	      B=temp;
	      (*B).number=j;
	      (*B).value=p[i][j];
	      (*B).next=NULL;
	      cout<<"(Node:"<<j<<" Weight:"<<(*B).value<<") ";
	    }
	}
      cout<<endl;
    }
  
}
	      
	    

int main()
{
  int n,**p,i,x,j;

  cout<<"Enter the number of elements:";
  cin>>n;

  p=new int*[n];
  for(i=0;i<n;i++)
    p[i]=new int[n];

  
  for(i=0;i<(n-1);i++)
    {
      for(j=i+1;j<n;j++)
	{
	  cout<<"Enter the  Weight between "<<i<<" and "<<j<<":";
	  cin>>x;
	  p[i][j]=p[j][i]=x;
	}
    }
  makelist(p,n);
}
