#include <stdio.h>
int main()
{
	int i,j,k,n;
	char c;
	scanf("%d %c",&n,&c);
	char z=c;
	for(i=1;i<=2*(2*n-2)-1;i++)
	{
		if(z=='[') z='A';
		if(z=='@') z='Z';
		z+=1;
	}
	for(i=1;i<=n;i++)
	{
		if(c=='[') c='A';
		if(c=='@') c='Z';
		if(z=='[') z='A';
		if(z=='@') z='Z';
		for(j=0;j<n-i;j++)
		{
			printf(" ");
		} 
		printf("%c",c++);
		for(k=0;k<2*i-3;k++)
		{
			printf(" ");
		}
		if(i!=1) printf("%c",z--);
		printf("\n");
	}
	for(i=n-1;i>0;i--)
	{
		if(c=='[') c='A';
		if(c=='@') c='Z';
		if(z=='[') z='A';
		if(z=='@') z='Z';
		for(j=0;j<n-i;j++)
		{
			printf(" ");
		}
		printf("%c",c++);
		for(k=0;k<2*i-3;k++)
		{
		printf(" ");
	}
	if(i!=1) printf("%c",z--);
	printf("\n");
	}
}
