#include <bits/stdc++.h>
 
using namespace std;
#define MAX 1550
 
vector<int> point[MAX]; 
bool vis[MAX];  
int dp[MAX][2];
 
void DFS(int root) {
    vis[root] = true;
  
    for (int i = 0; i < point[root].size(); i++) {
        int next = point[root][i];  
        if (vis[next])  
            continue; 
        DFS(next);
        dp[root][0] += dp[next][1];
        dp[root][1] += min(dp[next][0], dp[next][1]);
    }
    dp[root][1]++;
}
 
int main() {
    int n;
    while (EOF != scanf("%d", &n)) {
        for (auto & i : point)
            i.clear();
        memset(vis, false, sizeof(vis));
        memset(dp, 0, sizeof(dp));
        for (int i, k; n; n--) {
            scanf("%d:(%d)", &i, &k);  
            for (int j; k; k--) {
                scanf("%d", &j);
                point[i].push_back(j);
                point[j].push_back(i);
            }
        }
        int root = 0;
        DFS(root);
        printf("%d\n", min(dp[root][0], dp[root][1]));
    }
    return 0;
}