#include<stdio.h>
int f(int m,int n);
int main()
{
    int m,n,ans;
    scanf("%d%d",&m,&n);
    ans=f(m,n);
    printf("%d\n",ans);

}
int f(int m,int n)
{
    if(m==1)
    return 1;
    if(n==1)
    return 1;
    if(m==n)
    return(1+f(m,n-1));
    else if(m<n)
    return f(m,m);
    else
    return(f(m-n,n)+f(m,n-1));
}