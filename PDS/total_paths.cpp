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

void transitive_closure(int **p,int n,int **q)
{
  int i,j;


  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  if(p[i][j]!=0)
	    q[i][j]=1;
	  else
	    q[i][j]=0;
	}
    }
  //print(q,n);
}

void check_node(int **p,int **q,int i,int j,int n,int* count)
{
  int k;
  for(k=0;k<n;k++)
    {
      if(q[i][k]==1)
	{
	  if(k==j)
	    {
	      (*count)++;
	      cout<<*count<<" ";
	      q[i][k]=q[k][i]=0;
	      //print(q,n);
	      check_node(p,q,i,j,n,count);
	    }
	  else
	    {
	      q[i][k]=q[k][i]=0;
	      print(q,n);
	      check_node(p,q,k,j,n,count);
	    }
	}
    }
  
}
	  
	
	      
void check_tree(int **p,int n,int **q)
{
  int i,j,flag=0,count=0;
  int *d=&count;
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  if(i!=j)
	    {
	      cout<<endl<<"Count:"<<*d<<" Elements"<<"("<<i<<","<<j<<")"<<endl;
	      transitive_closure(p,n,q);
	      //print(q,n);
	      check_node(p,q,i,j,n,d);
	      
	      if(count!=1)
		{
		  flag=1;
		  break;
		}
	      count=0;
	      
	    }
	}     
    }
  if(flag==1)
    cout<<endl<<"Not a tree"<<endl;
  else
    cout<<endl<<"A tree"<<endl;
}
	      
	    

int main()
{
  int n,**p,**q,i,x,j;

  cout<<"Enter the number of elements:";
  cin>>n;

  p=new int*[n];
  for(i=0;i<n;i++)
    p[i]=new int[n];
  
  q=new int*[n];
  for(i=0;i<n;i++)
    q[i]=new int[n];

  
  for(i=0;i<(n-1);i++)
    {
      for(j=i+1;j<n;j++)
	{
	  cout<<"Enter the  Weight between "<<i<<" and "<<j<<":";
	  cin>>x;
	  p[i][j]=p[j][i]=x;
	}
    }
  //makelist(p,n);
  cout<<"Transitive Closure:"<<endl;
  transitive_closure(p,n,q);
  print(q,n);
  check_tree(p,n,q);
}
