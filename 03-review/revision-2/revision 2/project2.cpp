#include<iostream>
#include<string>
#include<math.h>
using namespace std;
void get_matrix(int *b,int (*c)[15],int n){
  int x=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      c[i][j]=b[x++];
    }
  }
}
void warshall(int (*a)[15],int N)
{    
    int i = 0,j=0,k=0;
    for (i = 0;i < N;i++) {                  
        for (j = 0;j < N;j++) {
            if (a[j][i]) {
                for (k = 0;k < N;k++) {
                    a[j][k] = a[j][k] | a[i][k];
                }
            } 
        }
    }
}
void Print_matrix(int (*c)[15],int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<c[i][j];
      if(j!=n-1) cout<<' ';
    }
    cout<<endl;
  }
}
int main(){
  string a[100];
  int n=0,b[150],c[15][15];
  while(cin>>b[n]) n++;
  get_matrix(b,c,int(sqrt(n)));
  warshall(c,int(sqrt(n)));
  Print_matrix(c,int(sqrt(n)));
 
}