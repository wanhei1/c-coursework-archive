 #include <math.h> 
#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;

int num=0;

void count(int n,int m){
	if(n<m+1){	
			num+=0;
			return;
	}
	else if(n==m+1){	
		num+=1;
		return ;
	}
	else{
		n=n-m-1;
		num += 1;
		int layer=1;	

		if(n==0||layer>m)
			return;
		int need;
		need=pow(2,layer)-1;	
		
		while(n-need>0){
			num+=pow(2,layer-1);
			layer++;			
			n-=need;
			need=pow(2,layer)-1;
			if(layer>m)	
				return ;
		}
		if(n-need==0){
			num+=pow(2,layer-1);
			return;
		}	
		else			
			count(n,layer-1);
				
	}
	
}
int main() {
    int n,m,t;
	
	cin>>t;
	while(t--){
		cin>>n>>m;
		num=0;	
		count(n,m);
		cout<<num<<endl;		
	}
	
    return 0;
}