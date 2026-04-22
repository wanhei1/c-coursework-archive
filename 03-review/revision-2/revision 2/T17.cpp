#include <cstring>
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    queue<string> b;
    while (n--)
    {
        string a;
        cin >> a;
        if (a[0] == 'A')
        {//新的同学抵达
            string a1;
            cin >> a1;
            b.push(a1);
        }
        else if (a[0] == 'L')
        {
            if (b.empty())
            {
                continue;
            }
            else
            {
                b.pop();
            }
        }
        else if (a[0] == 'Q' && a[5] == 'H')
        {
            if (b.empty())
            {
                cout << "Empty queue" << endl;
            }
            else
            {
                cout << b.front() << endl;
            }
        }
        else if (a[0] == 'Q' && a[5] == 'T')
        {
            if (b.empty())
            {
                cout << "Empty queue" << endl;
            }
            else
            {
                cout << b.back() << endl;
            }
        }
    }
    return 0;
}
