#include<stdio.h>
int main()
{
long n,b,i,j,a[10000],c=0;
scanf("%d",&n);
for (i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n-1;i++)
{
    for(j=0;j<n-i-1;j++)
{
    if(a[j]>a[j+1])
{
    b=a[j];
    a[j]=a[j+1];
    a[j+1]=b;
}}}
for (i=1;i<n;i++)
{
    a[i]=a[i]+a[i-1];
}
for (i=1;i<n;i++)
{
    c+=a[i];
}
printf("%ld\n",c);
return 0;
}
