#include<stdio.h>  
#include<stdlib.h>  
#include<math.h>  
long x[100005]={0},y[100005]={0},z[100005]={0};  
int comp(const void*a, const void*b)  
{  
     return *(int *)a-*(int *)b;
}    
int main()  
{   
    int n,i;  
    long long s=0;  
    long m,o;  
    scanf("%d",&n);  
    for(i=0;i<n;i++)  
    {  
        scanf("%ld  %ld",&x[i],&y[i]);  
    }        
    qsort(y,n,sizeof(long),comp); 
    m=y[n/2];  
    for(i=0;i<n;i++)    
    {  
        s+=fabs(y[i]-m);  
    }           
    qsort(x,n,sizeof(long),comp);
    for(i=0;i<n;i++)
    {  
        z[i]=x[i]-i;  
    }     
    qsort(z,n,sizeof(long),comp);  
    o=z[n/2];      
    for(i=0;i<n;i++)    
    {  
        s+=fabs(x[i]-i-o);  
    }      
    printf("%lld\n",s);  
    return 0;  
}  
