#include<bits/stdc++.h>
using namespace std;

int map[1000][1000] = {0};
int vir[1000][1000] = {0};
int m, n, StartX, StartY, EndX, EndY;
int trend[4][2] = {{0,  1},
                   {0,  -1},
                   {1,  0},
                   {-1, 0}};
struct Node
{
    int x, y, dir,turn;
};

void BFS()
{
    queue<Node> q;
    Node k0, k1, t0;
    bool flag = false;
    for (int i = 0; i < 4; i++)
    {
        t0.x = StartX + trend[i][0];
        t0.y = StartY + trend[i][1];
        t0.dir = i;
        t0.turn = 1;
        vir[t0.x][t0.y] = t0.turn;
        q.push(t0);
    }
    while (!q.empty())
    {
        k0 = q.front();
        q.pop();
        if (k0.x == EndX && k0.y == EndY)
        {
            flag = true;
            cout << "TRUE" << endl;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            k1.x = k0.x + trend[i][0];
            k1.y = k0.y + trend[i][1];
            k1.dir = i;
            if (k1.dir != k0.dir)
            {
                k1.turn = k0.turn + 1;
            }
            else
            {
                k1.turn = k0.turn;
            }

            if (k1.turn > 3 || k1.x < 0 || k1.y < 0 || k1.x > m - 1 || k1.y > n - 1)
            {
                continue;
            }
            if (map[k1.x][k1.y] != 0 && map[k1.x][k1.y] != map[EndX][EndY])
            {
                continue;
            }
            if (vir[k1.x][k1.y] == 0 || vir[k1.x][k1.y] >= k1.turn)
            {
                vir[k1.x][k1.y] = k1.turn;
                q.push(k1);
            }
        }
    }
    if (!flag)
    {
        cout << "FALSE" << endl;
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    cin >> StartX >> StartY >> EndX >> EndY;
    BFS();
    return 0;
}
