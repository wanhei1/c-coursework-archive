#include <stdio.h>  
#include <math.h>  
#include <string.h>  
int main()  
{  
    int a,n;  
    int ans=1;  
    int m=1;  
    scanf("%d %d",&a,&n);  
    if(n==0){  
        ans=1;  
        printf("The last 3 numbers is %d.\n",ans);  
    }else{  
        for(int i=1;i<=n;i++){  
            ans=ans*a%1000;  
        }  
        for(int i=1;i<=n;i++){  
            a*=a;  
            if(a>=1000){  
                m=0;  
                break;  
            }  
        }  
        if(m){  
            printf("The last 3 numbers is %d.\n",ans);  
        }else{  
            printf("The last 3 numbers is %03d.\n",ans);  
        }  
    }  
    return 0;    
}  