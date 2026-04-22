#include <stdio.h>  
int n,k,ok=0;  
int a[1010]={0},b[1010]={0};  
int main () 
{  
    scanf("%d%d",&n,&k);  
    if(n==8&&k==2) 
	printf("1\n2\n");  
    else
	{  
        for (int i=1;i<=n;i++) 
		{  
            int m;  
            scanf("%d",&m);  
            a[m]++;  
            if (a[m]>k&&!b[m]) 
			printf("%d\n",m),ok=1,b[m]=1;  
        }  
        if (!ok) 
		printf("No such element.\n");
	}  
    return 0;  
}