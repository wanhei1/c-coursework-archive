#include<bits/stdc++.h>  
using namespace std; 
const int A = 1e3 + 10; 
int n,m,k,xa,ya,xb,yb;
char t1[A][A];
int s[A][A];
bool v[A][A];
 
void bfs() {  
   	queue<pair<int,int>> q; 
    v[xa][ya] = true; 
    s[xa][ya] = 0; 
  	q.push(make_pair(xa,ya)); 
   
    while ( q.size() ) { 
        auto cur = q.front(); 
        q.pop(); 
    	for (int w=1;w<=k;w++) { 
            if ( (cur.first-w>=1) && (t1[cur.first-w][cur.second]=='.') ) { 
                if (!v[cur.first-w][cur.second]) { 
                    v[cur.first-w][cur.second] = true; 
                    s[cur.first-w][cur.second] = s[cur.first][cur.second] + 1; 
                    q.push(make_pair(cur.first-w,cur.second)); 
                } 
                else continue; 
            } 
        	else break; 
        }  
        for (int s_d=1;s_d<=k;s_d++) { 
            if ( (cur.first+s_d<=n) && (t1[cur.first+s_d][cur.second]=='.') ) { 
                if ( !v[cur.first+s_d][cur.second] ) { 
                    v[cur.first+s_d][cur.second] = true; 
                    s[cur.first+s_d][cur.second] = s[cur.first][cur.second] + 1; 
                    q.push(make_pair(cur.first+s_d,cur.second)); 
                } 
                else continue; 
            } 
            else break; 
        }  
   		 for (int a_l=1;a_l<=k;a_l++) { 
    	    if ( (cur.second-a_l>=1) && (t1[cur.first][cur.second-a_l]=='.') ) { 
    	        if ( !v[cur.first][cur.second-a_l] ) { 
        	        v[cur.first][cur.second-a_l] = true; 
            	    s[cur.first][cur.second-a_l] = s[cur.first][cur.second] + 1; 
        	  	    q.push(make_pair(cur.first,cur.second-a_l)); 
            	} 
            	else continue; 
        	} 
        	else break; 
    	}   
    	for (int d_r=1;d_r<=k;d_r++) { 
        	if ( (cur.second+d_r<=m) && (t1[cur.first][cur.second+d_r]=='.') ) { 
            	if ( !v[cur.first][cur.second+d_r] ) { 
                	v[cur.first][cur.second+d_r] = true; 
                	s[cur.first][cur.second+d_r] = s[cur.first][cur.second] + 1; 
                	q.push(make_pair(cur.first,cur.second+d_r)); 
            	} 
            	else continue; 
        	} 
        	else break; 
    	}  
    
    	if (s[xb][yb]!=-1) goto z ;
    } 
    z: ;
} 
 
int main(){ 
    
	void bfs(); 
   	memset(s,-1,sizeof(s)); 
  	memset(v,false,sizeof(v)); 
  
  	scanf("%d %d %d",&n,&m,&k); 
    for (int i=1;i<=n;i++) { 
       	getchar(); 
     	for (int j=1;j<=m;j++) { 
            t1[i][j] = getchar(); 
      	}	 
  	}	 
  	scanf("%d %d %d %d",&xa,&ya,&xb,&yb); 
   
   	bfs(); 
 
  	cout << s[xb][yb] << endl;  
  return 0; 
}  