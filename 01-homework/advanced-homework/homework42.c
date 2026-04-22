#include <stdio.h>
int main()
{
int b,c;
scanf("%d",&b);
c=1;
while(b>1)
{c=(b+c-1)*2;
b=b-1;}
if(c>1)
{printf("The monkey got %d peaches in first day.\n",c);}
else if(c==1)
{printf("The monkey got %d peach in first day.\n",c);
}
}