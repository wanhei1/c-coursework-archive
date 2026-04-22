#include<iostream>
#include<cstdlib>
#define N 105 
using namespace std;
 
int v[N][N];
int c[N][N]; 
int a[N]; 
int n; 
 
void minproduct()
{
	for(int i=1;i<=n;i++) v[i][i]=0; 
	for(int lh=2;lh<=n;++lh)
	{
		for(int st=1;st<=n-lh+1;++st)  
		{
			int ed=st+lh-1; 
			v[st][ed]=v[st+1][ed]+a[st-1]*a[st]*a[ed];
			c[st][ed]=st;
			for(int ct=st+1;ct<ed;++ct)
			{
				int pt=v[st][ct]+v[ct+1][ed]+a[st-1]*a[ct]*a[ed];
				if(pt<v[st][ed]) 
				{
					v[st][ed]=pt;
					c[st][ed]=ct;
				}
			}
		} 
	} 
}
 
void zprint(int s,int e)
{
	if(s==e) cout<<'A'<<s;
	else
	{
		cout<<'(';
		zprint(s,c[s][e]);
		zprint(c[s][e]+1,e);
		cout<<')';
	}
} 
 
 
int main(){
	cin>>n;
	for(int i=0;i<=n;++i) cin>>a[i];
	if(n>1)
	{
		minproduct(); 
		cout<<v[1][n]<<endl;
		zprint(1,n);
		cout<<endl;
	}
	else
	{
		cout<<0<<endl;
		cout<<"(A1)"<<endl;
	}
	return 0;
} 