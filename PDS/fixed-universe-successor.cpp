#include <stdio.h>
#include <iostream>
//#include <new.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <math.h>

#define valu 6

using namespace::std;

int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}

int lengthCoun(int x)
{
  int lengthCount = 0;
  for(; x != 0; x /= 10, lengthCount++);
  return lengthCount;
}

int high(int x)
{
  int k;
  int i;
  k=convertDecimalToBinary(x);
  i=k/(pow(10,(lengthCoun(k)+1)/2));
  return convertBinaryToDecimal(i);
}

int low(int x)
{
  long long int k;
  int i;
  k=convertDecimalToBinary(x);
  i=k/(pow(10,(lengthCoun(k)+1)/2));
  k=k-i*(pow(10,(lengthCoun(k)+1)/2));
  return convertBinaryToDecimal(k);
}


void initU(int *Universe,int maximum_value, int n)
{
  int i;
  srand(49);
  for(i=0;i<maximum_value;i++)
    Universe[i]=0;

  for(i=0;i<valu;i++)
    Universe[rand()%n]=1;
  Universe[n]=1;
}

void initu(int **Univ,int maximum_value,int root_n,int n)
{
  int i,j,k;
  srand(49);
  for(i=0;i<root_n;i++)
    for(j=0;j<root_n;j++)
      Univ[i][j]=0;
  for(i=0;i<valu;i++)
  {
    k=rand()%n;
    Univ[high(k)][low(k)]=1;
  }
  int t=rand()%n;
  cout<<t<<":Rand "<<convertDecimalToBinary(t)<<":convertDecimalToBinary "<<high(t)<<":high "<<low(t)<<":low"<<endl;
}

void successor(int *Universe,int n, int x)\
{
  int i;
  for(i=x+1;i<n;i++)
    if(Universe[i]==1)
      break;
  cout<<i;
}

int main()
{
  int n,t,i,j,x,**Univ,maximum_value;

  cout<<"Enter the maximum value that you want to insert in the array"<<endl;
  cin>>n;

  t=(log (n))/(log (2));
  if(t%2==0)
   maximum_value=pow(2,t+2);
  else
   maximum_value=pow(2,t+1);
  int *Universe=new int[maximum_value];
  initU(Universe,maximum_value,n);


  Univ=new int*[n];
  int root_n=pow(maximum_value,0.5);
  for(i=0;i<root_n;i++)
    Univ[i]=new int[root_n];
  initu(Univ,maximum_value,root_n,n);
  for(i=0;i<root_n;i++)
  {
    for(j=0;j<root_n;j++)
      {cout<<Univ[i][j]<<" ";}
    cout<<endl;
  }

  cout<<"Enter the value who's successor you want to find"<<endl;
  cin>>x;

  int start_s=clock();
  successor(Universe,n,x);
  int stop_s=clock();
  cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*100000 << endl;


}
