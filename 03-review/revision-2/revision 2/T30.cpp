#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int A = 101;
int n,q,W,V,a[A],b[A],c[A]; 
ll f[511][511];
int main(){
	scanf("%d %d",&n,&q);
	memset(f,-1,sizeof(f));
	f[0][0] = 0;
	for (int i=1;i<=n;i++) {
		scanf("%d %d %d",&a[i],&b[i],&c[i]);	
	}
	for (int i=1;i<=n;i++) {
		
		for (int j=500;j>=0;j--) {
			for (int k=500;k>=0;k--) {
				if ( f[j][k]>=0 ) {
					if (j+a[i]<=500) {
						f[j+a[i]][min(k+b[i],500)] = max(f[j][k]+c[i],f[j+a[i]][min(k+b[i],500)]);
					}
				}
			}
		}
		
	} 
	for (int i=0;i<q;i++) {
		scanf("%d %d",&W,&V);
		ll m = -1;
		for (int j=0;j<=W;j++) {
			for (int k=V;k<=500;k++) {
				m = max( m,f[j][k]);
			}
		}
		cout << m << endl;
	}  
	return 0;
}