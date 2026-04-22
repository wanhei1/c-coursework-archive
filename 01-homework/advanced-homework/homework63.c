#include <stdio.h>  
double sum(int n)
{
    if(n==1)
    return 1;
    else if (n%2==0)
    return 1/(double)n+sum(n-1);
    else if (n%2==1)
    return -1/(double)n+sum(n-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    double y=sum(n);
    if(y==(int)y)
    printf("%d\n",(int)y);
    else 
    printf("%f\n",y);
    return 0;
}