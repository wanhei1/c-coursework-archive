//达拉崩吧的酒宴
#include<stdio.h>
#include<math.h>

int main(){
    double T;
    double a,b;
    long long int n;
    scanf("%lf",&T);
    for(a=1;a<=T;a++){
        scanf("%lld",&n);
        b=log(n)/log(2);
        if (b!=(int)b){
    
            b++;
        }
            printf("%d\n",(int)b);
    }
    return 0;



}