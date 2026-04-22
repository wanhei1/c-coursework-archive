#include<stdio.h>  
   int main()  
{  
    int n,v,temp1,temp2,s=0,m=0;
    scanf("%d %d",&n,&v);   
    int a[3000],b[3000];  
    for(int i=0;i<n;i++)   
    {  
       scanf("%d %d",&a[i], &b[i]);
    }       
    for(int j=1;j<=n-1;j++)  
     for(int i=0;i<n-j;i++)  
      if(a[i]>a[i+1])
      {  
        temp1=a[i];temp2=b[i];  
        a[i]=a[i+1];b[i]=b[i+1];  
        a[i+1]=temp1;b[i+1]=temp2;  
      }         
    for(int c=1;c<=a[n-1]+1;c++)  
    {  
        for(int d=0;d<n;d++)  
        {  
            if(a[d]==c-1||a[d]==c)
            {
                m+=b[d]; 
            }  
        }
        if(c==1)  
        {  
            if(v>m)   
            {  
                s+=m;  
                for(int d=0;d<n;d++)  
                {  
                    if(a[d]==1) b[d]=0;  
                }  
            }  
              
            else  
            {  
                
                 
                s+=v;  
                for(int d=0;d<n;d++)  
                {  
                    if(a[d]==1) {
                        b[d]-=v;
                    }
                } 
            }  
        }            
        else  
        {  
            if(v>m)    
            {  
                s+=m;  
                for(int d=0;d<n;d++)  
                {  
                    if(a[d]==c-1||a[d]==c) {
                        b[d]=0;
                        } 
                }    
                 
            }                
            else  
            {  
               
                m=v;s+=v;  
                for(int d=0;d<n;d++)  
                {  
                    if(a[d]==c-1&&b[d]-m<0)  
                    {  
                        m-=b[d];
                        b[d]=0; 
                    }  
                      
                    else if(a[d]==c-1&&b[d]-m>0)  
                    {  
                        b[d]-=m;
                        break;
                    }  
                      
                    else if(a[d]==c)  
                    {  
                        b[d]-=m;
                        m=0; 
                    }

                }
            }  
        }   
    }   
    printf("%d\n", s);  
    return 0;
}  
