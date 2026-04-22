#include <stdio.h>
int main()
{
    int M,N,n,s=0;
    scanf("%d%d",&M,&N);//输入
    s=(M+N)*(N-M+1)/2;//等差数列求和。
    printf("The sum from %d to %d is %d.\n",M,N,s);//输出结果。
    return 0;
}