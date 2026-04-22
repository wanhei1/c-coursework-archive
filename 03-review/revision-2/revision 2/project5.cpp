#include <bits/stdc++.h>
using namespace std;  
int main(){  
    int z[18],n=0,rank=1,res;  
    for(int i=0;i<=17;++i) 
    z[i]=i;   //初始化模18整数加法群z  
    scanf("%d",&n);  
    res=n;  
    //循环运算直到结果为幺元0   
    while(res!=z[0])       
    {  
        res=(res+n)%18;  
        ++rank;  
    }  
    printf("%d\n",rank);  
}  