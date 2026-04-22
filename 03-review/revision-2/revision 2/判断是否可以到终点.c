#include <stdio.h>  
int n,k,ok=0;  
int gcd(int m,int n) 
{  
    return n==0? m:gcd(n,m%n);  
}  
int a[1010]={0},b[1010]={0};  
int main () 
{  
    int x1,y1,x2,y2;  
    scanf("%d,%d",&x1,&y1);  
    scanf("%d,%d",&x2,&y2);  
    if(gcd(x1,y1)==gcd(x2,y2)&&x1<=x2&&y1<=y2) 
	printf("Yes.\n");  
    else 
	printf("No.\n");  
    return 0;  
}