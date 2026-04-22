#include<iostream>
#include<cstdio>
#include<stack>
#define WIDE 200005
int B[WIDE];
std::stack <int> c;
int main(void)
{
	int i,m,n;
	while (scanf("%d", &n) != EOF)
	{
	
		while (!c.empty())
			c.pop();
		m = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &B[i]);
			if (B[i] > m)
				m = B[i];
		}
		for (i = 0; i < n; i++)
			B[i] = (m - B[i]) % 2;
		for (i = 0; i < n; i++)
		{
			if (c.empty())
				c.push(B[i]);
			else if (B[i] == c.top()) 
				c.pop();
			else 
				c.push(B[i]);
		}
		if (c.size() <= 1)
			puts("YES");
		else
			puts("NO");
	}
}