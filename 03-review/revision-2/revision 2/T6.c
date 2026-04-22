#include <stdio.h> 
#include <string.h> 
int main() 
{ 
	int T,i; 
	long long int j=0,wa,wb,wc,wd,we; 
	scanf("%d",&T); 
    for(i=0;i<T;i++) 
    { 
    	char a[100000],b[100000],c[100000],d[100000],e[100000]; 
        if(i==0) 
        getchar();  
        scanf("%s",b); 
        scanf("%s",c); 
        wd=strlen(b); 
        we=strlen(c); 
        for(j=0;j<wd;j++) 
        d[j]=b[wd-1-j]; 
        d[wd]='\0'; 
        for(j=0;j<we;j++) 
        e[j]=c[we-1-j]; 
        e[we]='\0'; 
        wb=strlen(d); 
        wc=strlen(e); 
        if(wb<wc) 
        { 
            for(j=0;j<wb;j++) 
            a[j]=d[j]+e[j]-48; 
            for(j=wb;j<wc;j++) 
            a[j]=e[j]; 
        } 
        else 
        { 
            for(j=0;j<wc;j++) 
            a[j]=d[j]+e[j]-48; 
            for(j=wc;j<wb;j++) 
            a[j]=d[j]; 
        } 
        wa=strlen(a); 
        a[wa]='\0'; 
        for(j=0;j<wa;j++) 
        if(a[j]=='2') 
        { 
            a[j]='0'; 
            if(a[j+1]==0) 
            { 
                a[j+1]=a[j+1]+49; 
                a[j+2]='\0'; 
                wa=strlen(a); 
            } 
            else 
            a[j+1]=a[j+1]+1; 
        } 
        else if(a[j]=='3') 
        { 
            a[j]='1'; 
            if(a[j+1]==0) 
            { 
                a[j+1]=a[j+1]+49; 
                a[j+2]='\0'; 
                wa=strlen(a); 
            } 
            else 
            a[j+1]=a[j+1]+1; 
        } 
        for(j=0;j<wa+2-wb;j++) 
        printf(" ");  
        printf("%s\n+",b);  
        for(j=1;j<wa+2-wc;j++)
        printf(" ");  
        printf("%s\n",c);  
        
        for(j=1;j<=wa+2;j++)  
        printf("-");  
        printf("\n  ");  
        
        for(j=0;j<wa;j++) 
        printf("%c",a[wa-1-j]);  
        printf("\n");  
        memset(d,0,sizeof(d));    
        memset(e,0,sizeof(e));    
        memset(a,0,sizeof(a));      
        memset(b,0,sizeof(b));    
        memset(c,0,sizeof(c)); 
    
    } 
    return 0; 
 } 
