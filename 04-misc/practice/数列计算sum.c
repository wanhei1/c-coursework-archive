#include<stdio.h>
int main()
{float sum=0.0,t;
int i,n;
scanf("%d",&n);
if(n>=1)
{
for(i=1;i<=n;i++)
{t=1.0/i;sum=sum+t;}
printf("sum=%f\n",sum);
}
}