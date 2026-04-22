#include<stdio.h>  
  
main()  
{  
    int a,b,c,d,x,y,n1,n2,p,Ans;  
    char op;  
    scanf("%d/%d %c %d/%d",&a,&b,&op,&c,&d);  
      
        switch(op)  
        {  
        case'+':  
            x=a*d+b*c;  
            y=b*d;  
            break;  
              
        case'-':  
            x=a*d-b*c;  
            y=b*d;  
            break;  
              
        case'*':  
            x=a*c;  
            y=b*d;  
            break;    
              
        case'/':  
            x=a*d;  
            y=b*c;  
            break;  
              
        default:  
        printf("Invalid input!");             
        }  
  
    if(x==0)  
    printf("%d/%d %c %d/%d = 0\n",a,b,op,c,d);  
      
     if(x>y)  
        {  
            n1=x;  
            n2=y;  
        }  
    else if(x<y)  
        {  
            n1=y;  
            n2=x;  
        }  
      
    p=n1%n2;  
        if(p!=0)  
        {  
            x/=p;  
            y/=p;     
        }  
        else  
        {  
            x/=n2;  
            y/=n2;  
        }  
          
    if(y<0)  
    {  
        y=-y;  
        x=-x;  
        printf("%d/%d %c %d/%d = %d/%d\n",a,b,op,c,d,x,y);  
    }   
      
    else if(y==1)  
    printf("%d/%d %c %d/%d = %d\n",a,b,op,c,d,x);  
      
    else  
    printf("%d/%d %c %d/%d = %d/%d\n",a,b,op,c,d,x,y);  
          
}  