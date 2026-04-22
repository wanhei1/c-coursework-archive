#include <stdio.h>
int findf(int n)
{
 if(n<=4&&n>=0)
  return 1;
 else if(n>4&&n%2==0)
  return findf(n-1)+findf(n-3);
 else if(n>4&&n%2==1)
  return findf(n-2)+findf(n-4);
 else
  return -1;
}
int main()
{  
 int n,s;  
 scanf("%d", &n);   
 s = findf(n);   
 printf("%d\n", s);  
 return 0;
}