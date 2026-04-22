#include <stdio.h>  
int main()  
{  
int a,n,i,j,b;  
    scanf("%d%d",&a,&n);  
    if(a>0&&n>0)  
    {  
    b=((a+2*(n-1))%10+(n-2))%10;  
        for(i=1;i<=n;i++)  
        {  
            if(i==1)  
            {  
                for(j=1;j<=n;j++)  
                {  
                if(a==10) a=0;  
                printf("%d",a++);  
                }  
                printf("\n");  
            }  
              
            if(i!=1&&i!=n)  
            {  
                if(b==-1)b=9;  
                printf("%d",b--);  
                for(j=0;j<(n-i-1);j++)  
                    printf(" ");  
                if(a==10) a=0;  
                printf("%d\n",a++);  
            }  
            if(i==n&&n!=1)  
            {  
                if(a==10) a=0;  
                printf("%d\n",a++);  
            }  
        }  
    }  
}