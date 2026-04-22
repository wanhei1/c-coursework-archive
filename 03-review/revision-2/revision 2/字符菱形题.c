#include <stdio.h> 
int main()
{
	int n,i,j,k;
	char a,b;
	scanf("%d %c",&n,&a);
	b=a+4*n-5;
	k=(b/26)-2;
	k=k*26;
	if(b>=91) b=b-k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++) printf(" ");
		printf("%c",a++);
		for(j=0;j<2*i-1;j++) printf(" ");
		if(b=='@') b='Z';
		if(i!=0) printf("%c",b--);
		printf("\n");
	}
	for(i=n;i>1;i--)
	{
		for(j=0;j<n-i+1;j++) printf(" ");
		if(a=='[') a='A';
		printf("%c",a++);
		for(j=0;j<2*(i-2)-1;j++) printf(" ");
		if(i!=2) printf("%c",b--);
		printf("\n");
	}
	return 0;
}