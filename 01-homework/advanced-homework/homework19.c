#include <stdio.h>
   
   int main(){
        int a,b,c,d;scanf("%d",&a);
        if(a==2){printf("The max prime number is %d.\n",a);
        }
        else  
        {b=a;c=b-1;
           while(b>1&&c>1)
    
   {d=b%c;
    
   if(d==0)
    
  {b=b-1;c=b-1;}
    
   else{c=c-1;}
    
   } printf("The max prime number is %d.\n",b);
    
}}