#include<stdio.h>
int main()
{
    int n, count();
    scanf("%d",&n);
    printf("%d\n",count(n,n-1));
    return 0;
}
int count (int n,int m)
{int a =0;
if(n<=1||m<=1)
{
    if(n<1||m<1)
    {
        a=0;
    }
else if(n==1||m==1)
{
    a=1;
}
}
else
{
    if(n==m)
    {
        a=count(n,m-1)+1;
    }
else
{
    a=count(n-m,m)+count(n,m-1);

}
}
return a;
}

