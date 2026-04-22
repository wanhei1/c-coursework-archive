#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
struct Sign
{
    long Idiom;
    bool v;

    Sign(long I, bool v1)
    {
        Idiom = I;
        v = v1;
    }
};
vector<Sign> b[300001];
struct A
{
public:
    long c;
    long d;
    A(long c1, long d1) : c(c1), d(d1)
    {

    }
};

struct Idiom
{
public:
    long I2;
    long I3;
    long I4;
    long I5;
};
queue<A> p;
int main()
{
    long m;
    cin >> m;
    for (long i = 0; i < m; i++)
    {
        Idiom t;
        cin >> t.I2 >> t.I3 >> t.I4 >> t.I5;
        b[t.I2].push_back(Sign(t.I5, 0));
    }

    Idiom Istart, Iend;
    cin >> Istart.I2 >> Istart.I3 >> Istart.I4 >> Istart.I5
        >> Iend.I2 >> Iend.I3 >> Iend.I4 >> Iend.I5;
    if (Istart.I2 == Iend.I2 && Istart.I3 == Iend.I3 &&
        Istart.I4 == Iend.I4 && Istart.I5 == Iend.I5)
    {
        cout << 1 << endl;
        return 0;
    }
    if (Istart.I5 == Iend.I2)
    {
        cout << 2 << endl;
        return 0;
    }
    A e(Istart.I5, 0);
    p.push(e);
    long M = 300000;
    while (!p.empty())
    {
        A tmp = p.front();
        for (long j = 0; j < b[tmp.c].size(); j++)
        {
            if (b[tmp.c][j].v == 0)
            {
                if (b[tmp.c][j].Idiom == Iend.I2)
                {
                    if (tmp.d + 3 <= M)
                    {
                        M = tmp.d + 3;
                    }
                }
                b[tmp.c][j].v = 1;
                A ReturnPos(b[tmp.c][j].Idiom, tmp.d + 1);
                p.push(ReturnPos);
            }
        }
        p.pop();
    }
    if (M != 300000)
    {
        cout << M << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
