#include<stdio.h>
#include<string.h>
int main()
{int i,j;
char a[20];
gets(a);
j=strlen(a);
for(i=0;i<j;i++)
if(a[i]!=a[j-i-1])
{printf("No\n");break;
}
if(i==j) printf("Yes\n");
return 0;
}