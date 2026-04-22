#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int S[MAXN];
int F[MAXN];
int N;

int main()
{
 
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> S[i] >> F[i];
    }
    sort(S, S + N);
    sort(F, F + N);

    int ans = 0;

    int tmpans = 0;
    int i = 0;
    int j = 0;
    while (i < N && j < N)
    {
        if (S[i] < F[j])
        {
            tmpans++;
            i++;
            ans = max(tmpans, ans);
        }
        else if (S[i] > F[j])
        {
            tmpans--;
            j++;
        }
        else
        {
            j++;
            i++;
            ans = max(ans, tmpans);
        }
    }
    cout << ans << endl;
    return 0;
}
