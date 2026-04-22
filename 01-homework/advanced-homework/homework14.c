#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
int main(int argc, char *argv[]) {  
    int n,a,b,c,d,e,f,g,i,j;
    j=0;  
    scanf("%d",&n);  
    a=pow(10,n);  
    for(i=1;i<a;i++)  
    {  
        b=i/100000;  
        c=(i-b*100000)/10000;  
        d=(i-b*100000-c*10000)/1000;  
        e=(i-b*100000-c*10000-d*1000)/100;  
        f=(i-b*100000-c*10000-d*1000-e*100)/10;  
        g=(i-b*100000-c*10000-d*1000-e*100-f*10)/1;  
        if((pow(b,n)+pow(c,n)+pow(d,n)+pow(e,n)+pow(f,n)+pow(g,n))==i&&i>=a/10)  
        {  
            printf("%d\n",i);  
            j++;  
        }  
    }  
    if(j==0)  
    {  
    printf("No output.\n");  
    }  
    return 0;  
}  
