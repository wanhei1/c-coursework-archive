#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
struct Str
{
public:
    int c;
    int h1;
};

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        int d[1000000];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &d[i]);
        }
        stack<Str> s;
        int colors[1000000] = { 0 };
        int Count = 0;

        for (int i = 0; i < n; i++)
        {
            Str tmp;
            scanf("%d", &tmp.h1);
            tmp.c = d[i];
            if (s.empty()|| tmp.h1 < s.top().h1)
            {
                s.push(tmp);
                if (colors[tmp.c] == 0)
                    Count++;
                colors[tmp.c]++;
            }
            else
            {
                while (tmp.h1 >= s.top().h1)
                {
                    colors[s.top().c]--;
                    if (colors[s.top().c] == 0)
                        Count--;
                    s.pop();

                    if (s.empty()|| tmp.h1 < s.top().h1)
                    {
                        s.push(tmp);
                        if (colors[tmp.c] == 0)
                            Count++;
                        colors[tmp.c]++;
                        break;
                    }
                }
            }

            printf("%d", Count);
            if (i < n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
