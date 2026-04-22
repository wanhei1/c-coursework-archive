#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;  
const int A = 2022;
int b[A],c[A],n,V,k=0;
void a(int i) {
	c[i] = 0;
	if (i==0) {
		int l=0;
		for (int j=0;j<n;j++) {
			l += b[j] * c[j];
		}
		if (l%V==0) k++;
	}
	else a(i-1);
	
	c[i] = 1;
	if (i==0) {
		int l=0;
		for (int j=0;j<n;j++) {
			l += b[j] * c[j];
		}
		if (l%V==0) k++;
	}
	else a(i-1);
 
}
int main(){      
    void d(int); 
    scanf("%d %d",&n,&V);
    
    for (int i=0;i<n;i++) {
		scanf("%d",&b[i]);   
	}
	a(n-1);
    printf("%d\n",k-1);
    return 0;  
}  