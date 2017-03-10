#include <stdio.h>

void chng(int x, int a[3])
{
  switch(x)
    {
    case 2:a[2]=a[1]+a[0];
      break;
    case 1:a[1]=a[0]+a[2];
      break;
    case 0:a[0]=a[1]+a[2];
    }
}


void fibo(int a[3], int n)
{
  int i,x;
  if(n==1||n==2)
    printf("%d\n", a[n-1]);
  else
    {
      for(i=3;i<=n;i++)
	{ 
       	  x=(i+2)%3;
	  chng(x,a);
	}
        printf("%d\n",a[x]);
    }
}

int main()
{
  int a[3]={1,2,3};

  int n;

  printf("Enter the value\n");
  scanf("%d",&n);

  fibo(a,n);
}
