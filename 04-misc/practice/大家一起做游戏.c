#include <stdio.h>  
#include <math.h>  
#include <string.h>  
int main()    
{    
    int m,n;  
    scanf("%d%d",&m,&n);  
    int a[m];  
    for(int i=0;i<m;i++){  
        a[i]=i+1;  
    }  
    int whe=1,k=0,i=0,xu;  
    while(whe){  
        if(a[i]!=0){  
            k++;i++;  
        }else i++;  
        if(k==n){  
            a[i-1]=0;  
            k=0;  
        }  
        i%=m;  
        int h=0;  
        for(int w=0;w<m;w++){  
            if(a[w]!=0){  
                h++;xu=w;  
            }  
        }  
        if(h==1)whe=0;  
    }  
    printf("The left child is NO %d.\n",a[xu]);  
    return 0;   
}  