#include <cstdio>
#include <algorithm>
 
#define MAXN 13
using namespace std;
 
int n;
int p[MAXN][MAXN], q[MAXN][MAXN], pq[MAXN][MAXN];
int pre[MAXN] = {0}; 
bool vis[MAXN] = {false};
int score = 0, best_score = 0; 
 
void backtrack(int i) {
    if (i > n) {
        best_score = max(best_score, score);
        return;
    }
    if (score + pre[n] - pre[i - 1] < best_score)
        return;
    for (int j = 1; j <= n; j++) {
        if (vis[j])
            continue;
 
        vis[j] = true;
        score += pq[i][j];
        backtrack(i + 1);
 
        vis[j] = false;
        score -= pq[i][j];
    }
}
 
int main() {
    scanf("%d", &n);
 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &p[i][j]);
 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &q[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            pq[i][j] = p[i][j] * q[j][i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            pre[i] = max(pre[i], pq[i][j]);
        pre[i] += pre[i - 1];
    }
    backtrack(1);
    printf("%d\n", best_score);
}