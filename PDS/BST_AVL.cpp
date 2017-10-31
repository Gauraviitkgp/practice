#include <stdio.h>
#include <iostream>
#include <new>

using namespace::std;

typedef struct A
{
  int value;
  int lef=0;
  int rig=0;
  struct A *left=NULL;
  struct A *right=NULL;
}Node;

void construct_BST(Node *nod,int x)
{
  if(x>nod->value && nod->right==NULL)
  {
    (nod->rig)++;
    Node *temp= new Node;
    nod->right = temp;
    (*temp).value=x;
  }
  else if(x<=nod->value && nod->left==NULL)
  {
    Node *temp= new Node;
    (nod->lef)++;
    nod->left = temp;
    (*temp).value=x;
  }
  else if(x>nod->value)
    {
      (nod->rig)++;
      construct_BST(nod->right,x);
    }
  else if(x<=nod->value)
    {
      (nod->lef)++;
      construct_BST(nod->left,x);
    }
}

void in_order(Node *nod)
{
  if(nod->left!=NULL)
    in_order(nod->left);
  cout<<nod->value<<" ";
  if(nod->right!=NULL)
    in_order(nod->right);
}

void search(int x,Node *nod)
{
  if(x==nod->value)
    cout<<"Present in the Tree"<<endl;
  else if(x>nod->value && nod->right!=NULL)
    search(x,nod->right);
  else if(x<nod->value && nod->left!=NULL)
    search(x,nod->left);
  else
    cout<<"Not in the tree"<<endl;
}

void single_left_rotation(Node *nod)
{
  
  Node *temp1,*temp2;
  
  temp1=nod;
  nod=nod->right;
  temp2=nod->left;
  nod->left=temp1;
  (nod->left)->right=temp2;

  nod->lef=nod->lef+2;
  (nod->left)->rig=(nod->left)->rig - 4;
  
}

void single_right_rotation(Node *nod)
{
  Node *temp1,*temp2;
  
  temp1=nod;
  nod=nod->left;
  temp2=nod->right;
  nod->right=temp1;
  (nod->right)->left=temp2;

  nod->rig=nod->rig+2;
  (nod->right)->lef=(nod->right)->lef - 4;
}

void double_right_rotation(Node *nod)
{
  single_left_rotation(nod->left);
  single_right_rotation(nod);
}

void double_left_rotation(Node *nod)
{
  single_right_rotation(nod->right);
  single_left_rotation(nod);
}


void check_rb(Node *nod)
{
  if(nod->left!=NULL)
    check_rb(nod->left);
    
  if(nod->lef-nod->rig>=2)
    {
      if(((nod->left)->rig)>((nod->left)->lef))
	double_right_rotation(nod);
      else
	single_right_rotation(nod);
    }
  else if(nod->rig-nod->lef>=2)
    {
      if(((nod->right)->lef)>((nod->right)->rig))
	double_left_rotation(nod);
      else
	single_left_rotation(nod);
    }
  
  if(nod->right!=NULL)
    check_rb(nod->right);
}

int main()
{
  int x;
  Node *Head=new Node;

  cout<<"Enter the value of first node:-";
  cin>>(*Head).value;

  while (1)
  {
    cout<<"Enter the value of next node(-493 to exit):-";
    cin>>x;
    if(x==-493)
      break;
    construct_BST(Head,x);
    check_rb(Head);
    cout<<endl<<Head->lef<<" : "<<Head->rig<<endl;
  }

  in_order(Head);
  cout<<endl;

  cout<<"Enter the value you want to search:-";
  cin>>x;
  search(x,Head);


}
