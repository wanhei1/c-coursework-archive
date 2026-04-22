#include<stdio.h>
long long n[100002][3];
long long max,sum;
char c;
int main()
{
    while(scanf("%lld",&sum)&&sum)
    {
        c=getchar();
        max=0;
        for(int i=1;i<=sum;i++)
        {
         scanf("%lld",&n[i][0]);
         n[i][1]=n[i][2]=0;
        }
        for(int i=2;i<=sum;i++)
        {
            if(n[i][0]>n[i-1][0])
            n[i][1]=0;
            else
            {
                int k=i-1-n[i-1][1]-1;
                while(k>0&&n[k][0]>=n[i][0])
                {
                    k=k-n[k][1]-1;
                }
                n[i][1]=i-k-1;
            }
        }
        for(int i=sum-1;i>=1;i--)
        {
            if(n[i][0]>n[i+1][0])
            n[i][2]=0;
            else
            {
                int k=i+1+n[i+1][2]+1;
                while(k<=sum&&n[k][0]>=n[i][0])
                {
                    k=k+n[k][2]+1;
                }
                n[i][2]=k-i-1;
            }
        }
        for(int i=1;i<=sum;i++)
        {
            if((n[i][1]+n[i][2]+1)*n[i][0]>max)
            max=(n[i][1]+n[i][2]+1)*n[i][0];
        }
        printf("%lld\n",max);
    }
    return 0;
}