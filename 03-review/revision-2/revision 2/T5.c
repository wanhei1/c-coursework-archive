#include<stdio.h>  
int main()  
{  
    int T;  
    scanf("%d",&T);  
    for(int i=1;i<=T;i++)  
    {  
        long int a[100000],b[100000],c[100000];  
        long int d,e,s = 0,m = 0;   
        scanf("%ld",&e);  
        for(long int i = 1; i <= e; i ++)  
        {  
                scanf("%ld",&a[i]);  
                  m = (m > a[i]) ? m : a[i];  
            b[i] = m;
        }   
        m = 0;  
        for(long int i = e; i >= 1; i --)  
        {  
            m = (m > a[i]) ? m : a[i];  
            c[i] = m;
        }  
        for(long int i = 1; i <= e; i ++)  
        {  
            if(b[i] > c[i])  
            {  
                b[i] = c[i];  

            } 
              s = s + (b[i] - a[i]); 
        }
        
        printf("%ld\n",s);  
    }     
	return 0;  
} 
