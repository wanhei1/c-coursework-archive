#include <iostream>
#include <queue>

using namespace std;
int N;
int map[100][100];
int color[100];

//-1,1两个颜色,0未染色
bool bfs(int s)
{
    queue<int> p;
    p.push(s);
    color[s] = 1;
    while (!p.empty())
    {
        int from = p.front();
        p.pop();
        for (int i = 0; i < N; i++)
        {
            if (map[from][i] && color[i] == 0)
            {
                p.push(i);
                color[i] = -color[from];//染成不同的颜色
            }
            if (map[from][i] && color[from] == color[i])//颜色有相同，则不是二分图
                return false;
        }
    }
    return true;
}

int main()
{
    freopen("E://test.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (color[i] == 0 && !bfs(i))
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}
