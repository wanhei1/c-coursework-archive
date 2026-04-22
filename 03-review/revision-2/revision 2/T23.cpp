#include <bits/stdc++.h>
using namespace std;
char m1[18][18],m2[18][18],r1[4][4],x[16];
int r[4][4],a[16];
int f = 0;
int test(int b);
int dfs(int b, int c);
int rotate(int n, int d, int e);
int h(int x, int y);
int testing(int u);
 
int test(int u){
    for (int i = 0; i < 16; i++){
        switch(m1[u][i]){
            case '0': a[0]++; break;
            case '1': a[1]++; break;
            case '2': a[2]++; break;
            case '3': a[3]++; break;
            case '4': a[4]++; break;
            case '5': a[5]++; break;
            case '6': a[6]++; break;
            case '7': a[7]++; break;
            case '8': a[8]++; break;
            case '9': a[9]++; break;
            case 'A': a[10]++; break;
            case 'B': a[11]++; break;
            case 'C': a[12]++; break;
            case 'D': a[13]++; break;
            case 'E': a[14]++; break;
            case 'F': a[15]++; break;
        }
    }
    for(int i = 0; i < 16; i++){
        if(a[i] == 0 || a[i] > 1){
            memset(a, 0, sizeof(a));
            return 0;
        }
    }
    memset(a, 0, sizeof(a));
    return 1;
}
int dfs(int u, int v){
    if(f == 1)
        return 0;
    if(v == 4){
        for(int i = 0; i < 4; i++){
            rotate(i, u, v);
            if(test((u - 1) * 4) == 1){
                f = 1;
                return 0;
            }
            else{
                h(u, v);
                r[u - 1][v - 1] = 0;
            }
        }
    }
    else{
        for (int i = 0; i < 4; i++){
            rotate(i, u, v);
            dfs(u, v + 1);
            if(test((u-1)*4) == 1){
                f = 1;
                return 0;
            }
            else{
                h(u, v);
            }
        }
    }
    return 0;
}
int rotate(int n, int x, int y){
    for (int i = 0; i < n; i++){
        for (int j = 3; j >= 0; j--){
            for (int k = 0; k < 4; k++){
                r1[3 - j][k] = m1[k+(x-1)*4][j+(y-1)*4];
            }
        }
        for (int jj = 0; jj < 4; jj++){
            for (int kk = 0; kk < 4; kk++){
                m1[jj + (x - 1) * 4][kk + (y - 1) * 4] = r1[jj][kk];
            }
        }
    }
    r[x - 1][y - 1] = n;
    return 0;
}
int h(int x, int y){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            m1[(x - 1) * 4 + i][(y - 1) * 4 + j] = m2[(x - 1) * 4 + i][(y - 1) * 4 + j];
        }
    }
    return 0;
}
 
int testing(){
    for (int i = 0; i < 16; i++){
        switch(x[i]){
            case '0': a[0]++; break;
            case '1': a[1]++; break;
            case '2': a[2]++; break;
            case '3': a[3]++; break;
            case '4': a[4]++; break;
            case '5': a[5]++; break;
            case '6': a[6]++; break;
            case '7': a[7]++; break;
            case '8': a[8]++; break;
            case '9': a[9]++; break;
            case 'A': a[10]++; break;
            case 'B': a[11]++; break;
            case 'C': a[12]++; break;
            case 'D': a[13]++; break;
            case 'E': a[14]++; break;
            case 'F': a[15]++; break;
        }
    }
    for(int i = 0; i < 16; i++){
        if(a[i] == 0 || a[i] > 1){
            memset(a, 0, sizeof(a));
            return 0;
        }
    }
    memset(a, 0, sizeof(a));
    return 1;
}
 
    int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        f = 0;
        for (int i = 0; i < 16; i++){
            scanf("%s", &m1[i]);
            for (int j = 0; j < 16; j++){
                m2[i][j] = m1[i][j];
            }
        }
        for (int i = 1; i < 5; i++){
            f = 0;
            dfs(i, 1);
        }
 
        for (int i1 = 0; i1 < 2; i1++)
        {
           
            for (int i2 = 0; i2 < 2; i2++)
            {
               
                for (int i3 = 0; i3 < 2; i3++)
                {
                    
                    for (int i4 = 0; i4 < 2; i4++)
                    {   
                        x[0] = m1[0][0+i1*3];
                        x[1] = m1[1][0+i1*3];
                        x[2] = m1[2][0+i1*3];
                        x[3] = m1[3][0+i1*3];
                        x[4] = m1[4][0+i2*3];
                        x[5] = m1[5][0+i2*3];
                        x[6] = m1[6][0+i2*3];
                        x[7] = m1[7][0+i2*3];
                        x[8] = m1[8][0+i3*3];
                        x[9] = m1[9][0+i3*3];
                        x[10] = m1[10][0+i3*3];
                        x[11] = m1[11][0+i3*3];
                        x[12] = m1[12][0+i4*3];
                        x[13] = m1[13][0+i4*3];
                        x[14] = m1[14][0+i4*3];
                        x[15] = m1[15][0+i4*3];
                        if(testing() == 1)
                            goto p;
                        for (int m = 0; m < 4; m++){
                                r[3][m] = (r[3][m] + 2) % 4;
                            }
                    }
                    for (int m = 0; m < 4; m++){
                                r[2][m] = (r[2][m] + 2) % 4;
                            }
                }
                for (int m = 0; m < 4; m++){
                                r[1][m] = (r[1][m] + 2) % 4;
                            }
            }
            for (int m = 0; m < 4; m++){
                                r[0][m] = (r[0][m] + 2) % 4;
                            }
        }
 
    p:
        int ans = 0, ans1 = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++){
                ans = r[i][j] + ans;
                ans1 = (r[i][j] + 2) % 4 + ans1;
            }
 
        if(ans < ans1){
            printf("%d\n", ans);
            for (int i = 0; i < 4;i++){
                for (int j = 0; j < 4;j++){
                    for (int k = 0; k < r[i][j];k++){
                        printf("%d %d\n", i+1, j+1);
                    }
                }
            }
        }     
        else
        {
            printf("%d\n", ans1);
            for (int i = 0; i < 4;i++){
                for (int j = 0; j < 4;j++){
                    for (int k = 0; k < (r[i][j]+2)%4;k++){
                        printf("%d %d\n", i+1, j+1);
                    }
                }
                
            }}}
            return 0;
            }