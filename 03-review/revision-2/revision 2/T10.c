#include<stdio.h>    
#include<string.h>    
int main()    
{    
    int n,i,j,d,s=0,x=0,y;  
    int l[100005]={0},r[100005]={0},b[50002]={0},c[50002]={0};   
    char a[100005];  
    scanf("%d",&n);        
     for(i=0;i<n;i++)    
    {    
        scanf("%s",a);     
        y=strlen(a);                
        for(j=0;j<y;j++)    
        {    
            if(a[j]=='(') 
            l[i]++;    
            else if(a[j]==')')    
            {    
                if(l[i]>0)  
                l[i]--;    
                else if(l[i]==0) 
                 r[i]++;        
            }    
        }    
    }    
      
    for(i=0,j=0,d=0;i<n;i++)   
    {   
       if(l[i]!=0&&r[i]==0) 
       b[j++]=i;   
        else if(l[i]==0&&r[i]!=0) 
        c[d++]=i;   
         else if(l[i]==0&&r[i]==0)
          x++;   
    }        
    for(i=0;i<j;i++)   
    {   
      for(n=0;n<d;n++)   
        {   
          if(l[b[i]]==r[c[n]])   
           {   
              s+=1;   
              r[c[n]]=-1;   
              break;   
           }   
        }   
    }   
    printf("%d\n",s+x/2);   
    return 0;
} 
