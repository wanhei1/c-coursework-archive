#include<bits/stdc++.h>
const int N=410, INF=0x3f3f3f3f;
using namespace std;  

int main()
{
	int n;
	cin >> n;
	int a[N];           
	int sum[N];         
	int Min[N][N];   
	int Max[N][N];   

	memset(Min,INF,sizeof Min);      
	memset(Max,0,sizeof Max);
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		a[i+n]=a[i];  
	} 
	
	for(int i=1;i<=2*n;i++)
	{
		Min[i][i]=0;   
		Max[i][i]=0;	
		sum[i]=sum[i-1]+a[i];   
	} 
	
	for(int len=2;len<=n;len++)      
	{
		for(int l=1;l+len-1<=2*n;l++)  
		{
			int r=l+len-1;  
	 		for(int k=l; k<r; k++)   
			{ 
	 			Min[l][r]=min(Min[l][r],Min[l][k]+Min[k+1][r]+sum[r]-sum[l-1]);
	 			Max[l][r]=max(Max[l][r],Max[l][k]+Max[k+1][r]+sum[r]-sum[l-1]);
	 		}
		} 
	} 

	int minn=INF, maxx=0;
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,Min[i][i+n-1]);         
		maxx=max(maxx,Max[i][i+n-1]);           
	}
	cout << minn << endl << maxx << endl ;
	return 0;	
}
