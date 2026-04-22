#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m,n,sum;
    sum=0;
    scanf("%d",&n);
    for (m=1;sum<n;m++)
    {
        sum+=m;
    }
    printf("%d\n",m-1);
    return 0;
    
}