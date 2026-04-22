#include <iostream>  
using namespace std;
typedef struct Node {
    Node* s = NULL;
    Node* e = NULL;
    int v;
} node;
node l[100001];
node* h[100001];
node* t1[100001];
int a[100001];
int main(void)
{
    int n, m, x, y;
    node* s;
    node* t;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        t = &(l[i]);
        t->v = i;
        h[i] = t;
        t1[i] = t;
    }
    for (int j = 0; j < m; j++)
    {
        scanf("%d %d", &x, &y);
        if (h[x] == NULL)
        {
            continue;
        }
        if (h[x]->e == NULL)
        {
            h[x]->e = h[y];
        }
        else if (h[x]->s == NULL)
        {
            h[x]->s = h[y];
        }
        if (h[y] != NULL && h[y]->e == NULL)
        {
            h[y]->e = h[x];
        }
        else if (h[y] != NULL && h[y]->s == NULL)
        {
            h[y]->s = h[x];
        }
        else if (h[y] == NULL)
        {
            h[y] = t1[x];
            t1[y] = h[x];
        }
        h[y] = t1[x];
        h[x] = NULL;
        t1[x] = NULL;
 
    }
    for (int i = 1; i <= n; i++)
    {
        node* c = h[i];
        int b = 0;
        if (c == NULL)
        {
            printf("%d\n", b);
            continue;
        }
        else
        {
            a[b++] = c->v;
        }
        if (c->e != NULL)
        {
            s = c;
            c = c->e;
            a[b++] = c->v;
        }
        else if (c->s != NULL)
        {
            s = c;
            c = c->s;
            a[b++] = c->v;
        }
        else
        {
            printf("%d %d\n", b, c->v);
            continue;
        }
        while (c->e != NULL && c->s != NULL)
        {
            if (c->e != s)
            {
                s = c;
                c = c->e;
                a[b++] = c->v;
            }
            else if (c->s != s)
            {
                s = c;
                c = c->s;
                a[b++] = c->v;
            }
        }
        printf("%d", b);
        for (int j = 0; j < b; j++)
        {
            printf(" %d", a[j]);
        }
        printf("\n");
    }
    return 0;
}