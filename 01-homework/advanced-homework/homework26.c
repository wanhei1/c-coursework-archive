#include <stdio.h>
#include<stdlib.h>
main()
{ int i,j,k=5,m;
char a;
scanf("%c",&a);
m=2*k-1;
for(i=2;i<=m;i++)
{
if(i<=k)for(j=1;j<=k+i-1;j++)
{if(j==k+i-1) printf("%c\n",a+i-1);
else if(j==k+1-i) printf("%c",a+i-1);
else printf(" ");}
else for(j=1;j<=m+k-i;j++)
{if(j==m+k-i) printf("%c\n",a+m-i);
else if(j==k+i-m) printf("%c",a+m-i);
else printf(" ");}
}
system("pause");
}