#include<iostream>
#include<cstdio>
#include<stack>
#define WIDE 200005
int B[WIDE];
std::stack<int> c;
int main(void)
{
	int m,n, i;
	while (scanf("%d", &n) != EOF)
	{
		m = 0;
		while (!c.empty())
			c.pop();
		for (i = 0; i < n; i++)
		{
			scanf("%d", &B[i]);
			if (B[i] > m)
				m = B[i];
		}
		for (i = 0; i < n; i++)
		{
			if (!c.empty() && B[i] == c.top())
				c.pop();
			else
			{
				if (!c.empty() && B[i] > c.top())
					break;
				else 
					c.push(B[i]);
			}
		}
		if (c.size() == 1 && c.top() == m)
			puts("YES");
		else if (c.size() == 0)
			puts("YES");
		else
			puts("NO");
	}
}