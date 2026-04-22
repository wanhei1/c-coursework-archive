#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int n,j;
    cin>>n;
    int a[n-1][n-1];
    int s[n-1][n-1];
 
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    
    for(int i=n-2;i>=0;i--)
    {
        for(j=i+1;j<n;j++)
        {
            s[i][i+1]=a[i][i+1];
        }
    }    
    
    for(int i=n-3;i>=0;i--)
    {
        for(j=i+1;j<n;j++)
        {
            s[i][j]=a[i][j];   
            for(int k = i+1;k < j;k++)
            {
                int t = s[i][k] + s[k][j];  
                if( t < s[i][j] ){s[i][j] = t;}
            }
        }
    }
    
    cout<<s[0][n-1];
    
}