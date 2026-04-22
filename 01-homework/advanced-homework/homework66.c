#include <stdio.h>
int a[100];
int game(int n,int m,int k)                          
{                                                    
	int i,j=0,count=0,g;                             
	do
	{
		if(a[m]!=0)                                  
		{
			j++;
			if(j==k)                                 
				a[m]=0;                              
			m++;                                   
			if(m>=n)                              
				m=0;                            
		}
		else
			while(a[m]==0)           
			{
				m++;
				if(m>=n)
					m=0;
			}
	}while(j<k);                         
	for(i=0;i<n;i++)                  
		if(a[i]!=0)
		{
			g=i;
			count++;
		}
	if(count==1)                    
	{
		if(g!=0)                       
			return(g);
		else
			return(n);                     
	}
	while(a[m]==0)                       
	{
		m++;
		if(m>=n)
			m=0;
	}
	return(game(n,m,k));                   
}

int main()
{
	int i,n,r;
	scanf("%d%d",&n,&r);                      
	for(i=0;i<n;i++)
		a[i]=i+1;                               
	printf("The left child is NO %d.\n",game(n,1,r));
	return 0;
}
