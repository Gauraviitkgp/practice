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

int k=1;

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

Node *single_left_rotation(Node *nod,Node *previous)
{
  int r=0;
  if(nod!=previous)
    r=1;
  Node *temp1,*temp2;

  temp1=nod;
  nod=nod->right;
  temp2=nod->left;
  nod->left=temp1;
  (nod->left)->right=temp2;

  nod->lef=(nod->left)->lef+1;
  (nod->left)->rig=(nod->left)->rig-nod->rig - 1;
  if(r==1)
    previous->right=nod;

  cout<<endl<<nod->value<<" LFunction C node value"<<endl;
  cout<<endl<<(nod->left)->value<<" LFunction L node value"<<endl;
  cout<<endl<<(nod->right)->value<<" LFunction R node value"<<endl;
  return nod;
}

Node *single_right_rotation(Node *nod,Node *previous)
{
  int r=0;
  if(nod!=previous)//if nod==previous than it is the case that nod is Head.
    r=1;//Changing the default value to 1
  Node *temp1,*temp2;

  temp1=nod;//temporary node of tip
  nod=nod->left;//Changing the tip to the left node of current tip
  temp2=nod->right;//temporary declaration of right node of new tip
  nod->right=temp1;//Now new right node of new tip would be equal to previous tip
  (nod->right)->left=temp2;//New right node(previous tip) left node is current pointing towards current tip. We changed it to right node of previous tip

  nod->rig=(nod->right)->rig+1;//Updating the values of right and left
  (nod->right)->lef=(nod->right)->lef-nod->lef - 1;
  if(r==1)
    previous->right=nod;//Check whether previous tip is a head or not

  cout<<endl<<nod->value<<" RFunction C node value"<<endl;
  cout<<endl<<(nod->left)->value<<" RFunction L node value"<<endl;
  cout<<endl<<(nod->right)->value<<" RFunction R node value"<<endl;
  return nod;
}

Node *double_right_rotation(Node *nod, Node *previous)
{
  nod->left=single_left_rotation(nod->left, previous);
  nod=single_right_rotation(nod,previous);
  return nod;
}

Node *double_left_rotation(Node *nod,Node *previous)
{
  nod->right=single_right_rotation(nod->right,previous);
  nod=single_left_rotation(nod,previous);
  return nod;
}


Node *check_rb(Node *nod,Node *previous, Node *Head)
{
  cout<<nod->value<<" nod.value in check_rb "<<nod->lef<<" lef "<<nod->rig<<" Rig"<<endl;

  if(nod->lef-nod->rig>=2)//Difference between number of branches in left and right should be >=2
  {
    if(((nod->left)->rig)>((nod->left)->lef))//If left node's No of right branches> No of left branches
    {
      nod=double_right_rotation(nod,previous);
      k=1;
      return nod;
    }
    else
    {
      nod=single_right_rotation(nod,previous);
      k=1;
      return nod;
    }
  }
  else if(nod->rig-nod->lef>=2)
  {
    if(((nod->right)->lef)>((nod->right)->rig))
    {
      nod=double_left_rotation(nod,previous);
      k=1;
      return nod;
    }
    else
    {
      nod=single_left_rotation(nod,previous);
      k=1;
      return nod;
    }
  }

  if(nod->left!=NULL)
    check_rb(nod->left,nod,Head);//check_rb until we complete all the left branches of the program

  if(nod->right!=NULL)
    check_rb(nod->right,nod,Head);

  k=0;//If there is no rotation return k=0
  return Head;
}

int main()
{
  int x;
  Node *Head=new Node;//First node of the tree

  cout<<"Enter the value of first node:-";
  cin>>Head->value;

  while (1)
  {
    k=1;
    cout<<"Enter the value of next node(-493 to exit):-";
    cin>>x;

    if(x==-493)
      break;

    construct_BST(Head,x);

    while(k==1)
      Head=check_rb(Head,Head,Head);//Until the tree is undergoing rotations check_rb function would continue to run. K=0 corresponds to no rotations where k=1(default) corresponds to >=1 rotations
  }

  cout<<"InOrder:- ";
  in_order(Head);
  cout<<endl;

  cout<<"Enter the value you want to search:-";
  cin>>x;
  search(x,Head);


}
