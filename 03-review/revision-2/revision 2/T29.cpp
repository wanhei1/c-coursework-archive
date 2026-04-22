    #include <bits/stdc++.h> 
    using namespace std; 
    typedef long long AA; 
    typedef unsigned long long AAA; 
    typedef pair<int, int> pp; 
    const int I = 0x3f3f3f; 
    const double E = 1e-8,P = acos(-1); 
    #define Max 200001
    vector<int> link[Max];
    vector<pp> side;
    int c[Max],d[Max],c_odd = 0;  
    inline int read()
    { 
        int x=0,f=1;char ch=getchar(); 
        while(ch<'0'||ch>'9') 
        { 
            if(ch=='-') 
                f=-1; 
            ch=getchar(); 
        } 
        while(ch>='0'&&ch<='9') 
        { 
            x=x*10+(ch-'0'); 
            ch=getchar(); 
        } 
        return f*x; 
    } 
     
    int main(){
        int n; 
        void dfs(int cur, int depth); 
        cin >> n; 
        memset(d, -1, sizeof(d)); 
        for(int i = 0; i < n - 1; i++){ 
            int x, y; 
            x = read(); 
            y = read(); 
            link[x].push_back(y);
            link[y].push_back(x); 
            side.emplace_back(x,y); 
        } 
        dfs(1,1);
        AA res = 0;
        for(pp line: side){
            AA son = Min(c[line.first], c[line.second]); 
            res += son * (n - son); 
        } 
        res += (AA)c_odd * (AA)(n - c_odd);
        cout << res / 2 << endl; 
        return 0; 
    } 
    void dfs(int cur, int depth){ 
        int total_child = 0; 
        d[cur] = depth; 
        if(depth & 1) c_odd += 1;
        for(int i: link[cur]){ 
            if(d[i] != -1)
             continue;
            else{
                dfs(i, depth + 1); 
                total_child += c[i];
            } 
        } 
        c[cur] = total_child + 1;
    }  