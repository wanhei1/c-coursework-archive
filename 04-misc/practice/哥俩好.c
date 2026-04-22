#include<stdio.h>

static int b[10] , k;

int multiply(int a[] , int x)
{	int i=0 , j=x-1;
	
	for(k=0 ; k<x/2 ; k++)
	{	b[k]=a[i++]*a[j--];
	}
	
	if(i==j)
	b[k++]=a[i];
}

int main()
{	int n , a[20] , i;
	
	scanf("%d",&n);
	
	for(i=0 ; i<n ; i++)
	{	scanf("%d",&a[i]);
	}
	
	multiply(a,n);
	
	for(i=0 ; i<k ; i++)
	printf("%d ",b[i]);
	printf("\n");
	
	return 0;
}