#include<stdio.h>
#define max_len 17
int  l[max_len][max_len],m,n;
int cur[max_len][max_len];
int ans = 256; 
void change(int *a) {
    if (*a == 1)
        *a = 0;
    else
        *a = 1;
}
void push(int l[][max_len], int i, int j) {
    change(&l[i][j]);
    if (i - 1 >= 0)
        change(&l[i - 1][j]);
    if (j - 1 >= 0)
        change(&l[i][j - 1]);
    if (i + 1 < n)
        change(&l[i + 1][j]);
    if (j + 1 < m)
        change(&l[i][j + 1]);
}
void getCur() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cur[i][j] = l[i][j];
}
int calc() {
    getCur();
    int s = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++) {
            if (cur[i][j] == 1) {
                s++;
                push(cur, i + 1, j);
            }
        }
 
    for (int i = 0; i < m; i++)
        if (cur[n - 1][i] == 1)
            return -1;
    return s;
}
void dfs(int s, int c) {
    if (s == m) {
        int b = calc();
        if (b == -1)
            return;
        if (b + c < ans)
            ans = b + c;
        return;
    }
 
    push(l, 0, s); 
    dfs(s + 1, c + 1);
 
    push(l, 0, s); 
    dfs(s + 1, c);
}
 
int main() {
    scanf("%d%d\n", &n, &m); 
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            c = getchar();
            l[i][j] = c - '0'; 
        }
        getchar();} 
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}