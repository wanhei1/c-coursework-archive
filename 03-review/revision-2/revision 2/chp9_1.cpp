#include<iostream>
#include<algorithm>
using namespace std;
int n;
int t[105][105],dp[105][105];
 
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1,j=1;i<=n;)
	{
		cin>>t[i][j];
		j++;
		if(j>i)
		{
			j=1;
			i++;
		}
	}
	dp[1][1]=t[1][1];
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + t[i][j];
		}
	}
	int maxx=0;
	for(int i=1;i<=n;i++) maxx=max(maxx,dp[n][i]);
	cout<<maxx<<endl;
	return 0; 
} 