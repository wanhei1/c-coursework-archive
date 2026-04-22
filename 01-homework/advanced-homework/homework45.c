#include<stdio.h>
int main()
{
char a[100],count,count2,right=1,i;
gets(a);
if(a[5]!='\0')
right=0;
if (a[4]>47&&a[4]<58)
{
for (i=0,count=0,count2=0;i<4;i++)
{
if (a[i]>64&&a[i]<91)
{
count++;
}
if (a[i]=='I')
right=0;
if (a[i]=='O')
right=0;
if (a[i]>47&&a[i]<58)
count2++;
}
if (count!=2||count2!=2)
{right=0;}
}
else
{right=0;}
if (right==1)
printf("ok.\n");
else
printf("no.\n");
}