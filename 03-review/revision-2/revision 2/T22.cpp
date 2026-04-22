#include <bits/stdc++.h>
using namespace std;
#define Max 105
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
 
struct node {
    int a, b, c,s;
    node(int a1, int y1,int y2, int s1) : a(a1), b(y1), c(y2), s(s1){}
};
queue<node> b;
int v[Max][Max][55];
char p[Max][Max];
 int main() {
    int n, m, T, k,sa,sb;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m,&k);
        for (int i = 0; i < n; ++i) {
            scanf("%s", &p[i]);
            for (int j = 0; j < m; ++j) {
                if (p[i][j] == 'S') {
                    sa = i;
                    sb = j;
                }
            }
        }
        memset(v, 0, sizeof(v));
        b.push(node(sa, sb, 0, 0));
        v[sa][sb][0] = 1;
        int result;
        int f = 0;
        while (!b.empty()) {
            node t = b.front();
            b.pop();
            if (p[t.a][t.b] == 'E') {
                result = t.s;
                f = 1;
                break;
            }
 
            for (int i = 0; i < 4; ++i) {
                int x = t.a + dx[i], y = t.b + dy[i];
                if((t.c+1)%k){
                    if (x < 0 || x >= n || y < 0 || y >= m || p[x][y] == '#' || p[x][y]=='*'||v[x][y][(t.c+1)%k] == 1)
                    continue;
                }
                else
                {
                    if (x < 0 || x >= n || y < 0 || y >= m || p[x][y] == '#'||v[x][y][(t.c+1)%k] == 1)
                    continue;
                }
                
                b.push(node(x, y, t.c+1, t.s + 1));
                v[x][y][(t.c+1)%k] = 1;
            }
        }    
        if(f)
            printf("%d\n", result);
        else
            printf("-1\n");
        while(!b.empty())
            b.pop();
    }
    return 0;
}
