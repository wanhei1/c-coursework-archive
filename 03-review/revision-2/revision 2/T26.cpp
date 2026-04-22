#include<bits/stdc++.h>  
#define AB long long
using namespace std;
AB c[500010];
AB dp[4][500010];
AB MAX(AB x, AB y)
{
    if (x > y)
        return x;
    else
        return y;
}
int main()
{
    AB n;
    cin >> n;
    for (AB i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (AB i = 1; i <= 3; i++)
    {
        AB mb = -1000000001;
        for (AB j = i; j <= n; j++)
        {
            if (i == j)
            {
                dp[i][j] = dp[i - 1][j - 1] + c[j]; 
            }
            else
            {
                mb = MAX(mb, dp[i - 1][j - 1]);
              
                dp[i][j] = MAX(dp[i][j - 1], mb) + c[j];
            }
        }
    }
    AB m = -1000000001;
    for (AB i = 3; i <= n; i++)
    {
        if (dp[3][i] > m)
        {
            m = dp[3][i];
        }
    }
    cout << m << endl;
    return 0;
}
