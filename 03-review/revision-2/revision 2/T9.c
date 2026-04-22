#include<stdio.h>   
#include<string.h>  
int main()  
{  
    int T,l,i,j,s=0,b,c,d,e;  
    char f[10] = {'f','a','t','t','y','h','a','p','p','y'}, s1,s2,s3;  
    scanf("%d",&T);  
    while(T--)  
    {  
        char a[1100];
        memset(a,'\0',sizeof(a));  
        scanf("%s", &a);
        l=strlen(a);       
        b=0;  
        for(i=0;i<l;i++)  
        {  
            s=0;
            b=0;
            for(j=0;j<10;j++) 
            {  
                if(a[i+j]!=f[j]&&s==0) 
                {  
                    s1=f[j];
                    d=i+j;
                    s++;  
                }  
                  
                else if(a[i+j]!=f[j]&&s==1)  
                {  
                    s++;  
                    e=i+j;
                    s2=f[j];  
                }  
                  
                else if(a[i+j]!=f[j]&&s>1)  
                    s++;  
            }  
              
            if(s==0)
            {  
                printf("%d %d\n",i+4,i+3);
                b=1;  
                break;  
            }  
              
            else if(s==1) 
            {  
                for(c=0;c<l;c++)  
                {  
                    if(a[c]==s1)  
                    {  
                        printf("%d %d\n",c+1,d+1); 
                        b=1;  
                        break;  
                    }  
                      
                    if(c==i)   
                    {  
                        c+=9; 
                        continue;  
                    }  
                }  
  
                if(b==1) break;  
            }  
              
            else if(s==2) 
            {  
                if(a[d]==s2&&a[e]==s1)  
                {  
                    printf("%d %d\n",d+1,e+1);  
                    b=1;  
                    break;  
                }  
            }  
                  
            else continue; 
       }    
       if(b==0) 
       printf("-1\n");
    }    
      return 0;
}  
