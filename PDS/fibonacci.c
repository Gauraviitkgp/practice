#include <stdio.h>

int main()
{
 long int a[100];
  int i,n;
  a[0]=1;a[1]=2;

  for(i=2;i<100;i++)
    a[i]=a[i-1]+a[i-2];

  printf("Enter the value of n\n");
  scanf("%d",&n);

  printf("%ld\n",a[n-1]);
  return 0;
}
