#include<bits/stdc++.h>
using namespace std;

#define N 100010

struct Point
{
    double x, y;
} points[N];

Point id[N];

int sort_x(Point p1, Point p2)
{
    return p1.x < p2.x;
}

int sort_y(Point p1, Point p2)
{
    return p1.y < p2.y;
}

double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double nearest(int l, int r)
{
    double d;
    if (l == r)
    {        return 10e100;
    }
    else if (l + 1 == r)
    {
        return dist(points[l], points[r]);
    }
    int m = (l + r) / 2;
    d = min(nearest(l, m), nearest(m + 1, r));
 
    int n = 0, i;
    for (i = l; i <= r; i++)
    {
        if (fabs(points[i].x - points[m].x) <= d)
        {
            id[n++] = points[i];
        }
    }
    sort(id, id + n, sort_y);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (id[j].y - id[i].y < d)
            {
                d = min(dist(id[i], id[j]), d);
            }
            else
            {
                break;
            }
        }
    }
    return d;
}

int main(int argc, char const *argv[])
{
    int n;
    double a1;
    while (true)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &points[i].x, &points[i].y);
        }
        sort(points, points + n, sort_x);
        a1 = nearest(0, n - 1);
        printf("%.2lf\n", a1 / 2);
    }
    return 0;
}