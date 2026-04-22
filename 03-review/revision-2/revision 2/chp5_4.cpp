#include<iostream>

#define MAXN 100
using namespace std;

int main()
{
    string tmp;
    cin >> tmp;
    int len = tmp.length();
    int num = 0;
    char ch[MAXN];
    int level[MAXN] = {0};
    int depth = -1;
    for (int i = 0; i < len; i++)
    {
        if (tmp[i] == '(')
        {
            depth++;
        }
        else if (tmp[i] == ')')
        {
            depth--;
        }
        else if (tmp[i] == ',')
        {
            continue;
        }
        else
        {
            ch[num] = tmp[i];
            level[num] = depth;
            num++;
        }
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < level[i]; j++)
        {
            cout << "    ";
        }
        cout << ch[i] << endl;
    }

    int degree[MAXN] = {0};
    int Node[MAXN] = {0}; 
    int max = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (level[j] == level[i])
            {
                break;
            }
            if (level[j] == level[i] + 1)
            {
                degree[i]++;
            }
        }
        Node[degree[i]]++;
        if (degree[i] > max)
        {
            max = degree[i];
        }
    }
    cout << "Degree of tree: " << max << endl;
    for (int i = 0; i <= max; i++)
    {
        cout << "Number of nodes of degree " << i << ": " << Node[i] << endl;
    }
    return 0;
}
