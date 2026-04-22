#include<bits/stdc++.h>  
#define mod 2147483647
#define AA long long
using namespace std;
AA cd[2005][2005];
AA H[2005];
AA MAX(AA x, AA y)
{
    if (x > y)
        return x;
    else
        return y;
}
AA MIN(AA x, AA y)
{
    if (x > y)
        return y;
    else
        return x;
}
int main()
{
    AA N;
    cin >> N;
    cin >> H[0];
    cd[1][H[0]] = 1;
    for (int i = 1; i <= N; i++)
    {
        cin >> H[i];
        for (int j = 0; j < N + 2; j++)
        {
            AA l = MIN(H[i - 1], j);
            AA r = MAX(H[i - 1], j);
            if (H[i] <= l)
            {
                cd[i][r] = (cd[i - 1][j] + cd[i][r]) % mod;
            }
            if (H[i] >= r)
            {
                cd[i][l] = (cd[i - 1][j] + cd[i][l]) % mod;
            }
            if (H[i] < r && H[i] > l)
            {
                cd[i][l] = (cd[i - 1][j] + cd[i][l]) % mod;
                cd[i][r] = (cd[i - 1][j] + cd[i][r]) % mod;
            }
        }
    }
    AA res = 0;
    for (int i = 0; i < N + 2; i++)
    {
        res = (res + cd[N][i]) % mod;
    }
    cout << res << endl;
    return 0;
}
