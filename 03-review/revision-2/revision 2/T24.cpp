#include <bits/stdc++.h>
#define SIZE 300001
int cause[SIZE] = { 0 }; 
int ans[SIZE] = { 0 }; 
int s; 
std::map<int, std::vector<int>> a; 
std::queue<int> b; 
bool bfs(int c, int d,bool v[]); 
int main(void) 
{ 
  int n, m, e, f; 
    scanf("%d %d", &n, &m); 
    for (s = 1; s <= m; s++) 
   { 
      bool v[SIZE] = { false }; 
        scanf("%d %d", &e, &f); 
        a[e].push_back(f); 
     if (bfs(f, e, v))
        { 
          printf("%d\n", s); 
          return 0; 
      } 
  } 
  printf("-1\n"); 
    return 0; 
} 
bool bfs(int c,int d,bool v[])
{ 
    int top = c; 
  b.push(c); 
    while (!b.empty()) 
 { 
       top = b.front(); 
       b.pop(); 
     for (auto x : a[top]) 
      { 
          if (x == d) 
              return true; 
           if (!v[x]) 
           { 
              b.push(x); 
             v[x] = true; 
         } 
      } 
  } 
 return false;                            
}