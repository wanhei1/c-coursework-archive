#include <bits/stdc++.h>
using namespace std;
int Essay(int x)
{
    if (x >= 'a' && x <= 'z')
    {
        return x - 'a' + 'A';
    }
    else
    {
        return x - 'A' + 'a';
    }
}

int main()
{
    char a[1000000];
    while (gets(a) != NULL)
    {

        if (a[0] >= 'a' && a[0] <= 'z')
        {
            a[0] = Essay(a[0]);
        }
        if (a[1] >= 'A' && a[1] <= 'Z')
        {
            a[1] = Essay(a[1]);
        }

        int b = 2;
        while (a[b] != '\0')
        {
            if (a[b - 1] == ' ')
            {
                if (a[b - 2] == '.' || a[b - 2] == '!' || a[b - 2] == '?')
                {
                    if (a[b] >= 'a' && a[b] <= 'z')
                    {
                        a[b] = Essay(a[b]);
                    }
                }
                else if (a[b - 2] == ',')
                {
                    if (a[b] >= 'A' && a[b] <= 'Z')
                    {
                        a[b] = Essay(a[b]);
                    }
                }
                else
                {
                    if (a[b] >= 'A' && a[b] <= 'Z')
                    {
                        a[b] = Essay(a[b]);
                    }
                }
            }
            else if ((a[b - 1] >= 'a' && a[b - 1] <= 'z') || (a[b - 1] >= 'A' && a[b - 1] <= 'Z'))
            {
                if (a[b] >= 'A' && a[b] <= 'Z')
                {
                    a[b] = Essay(a[b]);
                }
            }
            b++;
        }
        puts(a);
    }
    return 0;
}
