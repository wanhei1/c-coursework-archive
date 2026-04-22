#include <stdio.h>  
#include <math.h>  
  
int main()   
{  
    float a,b,c;  
    float d,e,f,g,p,x,y,x1,x2;  
      
    scanf("%f %f %f",&a,&b,&c);  
      
    if(a==0&&b==0)  
    printf("Input error!\n");  
      
      
    p=a+b;  
    d=b*b-4*a*c;  
    if(p!=0&&d>=0)  
        {  
            e=sqrt(d);  
            x1=(-b+e)/(2*a);  
            x2=(-b-e)/(2*a);  
            x=-c/b;  
            y=c/b;  
              
            if (a==0&&c!=0)  
            printf("x=%.6lf\n",x);  
              
            else if(a==0&&c==0)  
            printf("x=%.6lf\n",y);  
              
            else if (x1==x2)  
            printf("x1=x2=%.6lf\n",x1);  
              
            else  
            printf("x1=%.6lf\nx2=%.6lf\n",x1,x2);  
        }  
    else if(p!=0&&d<0)  
        {  
            e=sqrt(-d);  
            f=-b/(2*a);  
            g=e/(2*a);  
                  
                if(f==0)  
                printf("x1=%.6lfi\nx2=-%.6lfi\n",g,g);  
              
                else  
                printf("x1=%.6lf+%.6lfi\nx2=%.6lf-%.6lfi\n",f,g,f,g);  
        }  
      
    return 0;  
}