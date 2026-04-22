#include<bits/stdc++.h>

using namespace std;
int main(){
    int l[205][205]={0},h[205][205]={0};
    int n , k ,j,i;
    scanf("%d %d",&n,&k);
    l[1][1]=h[1][1]=1;
    for(int i=2;i<=n;i++){
        h[1][i]=1;
    for(int j=3;j<=n;j++)
    {
        for(int a=0;a<j;a++)
        {
           l[j][i]= (l[j][i]+l[a][i-1]*l[j-k-1][i-1]*2%9901)%9901;
          
        }
        h[j][i]=(h[j][i]+l[j][i])%9901;
    }
    printf("%d\n",l[n][k]);}
    return 0;

}