#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>
using namespace std;

bool JudgeOpt(char a, char b)
{
	int value1 = 0, value2 = 0;
	switch(a)
	{
		case '(': value1 = 1;break;
		case '+': value1 = 3;break;
		case '-': value1 = 3;break;
		case '*': value1 = 5;break;
		case '/': value1 = 5;break;
		case '^': value1 = 7;break;
		case ')': value1 = 9;break;
	}
	switch(b)
	{
		case '(': value2 = 1;break;
		case '+': value2 = 3;break;
		case '-': value2 = 3;break;
		case '*': value2 = 5;break;
		case '/': value2 = 5;break;
		case '^': value2 = 7;break;
		case ')': value2 = 9;break;
	}
	
	if(value1 - value2 < 0)
		return false;
	else
		return true;
}
int main()
{
	int n = 0;
	scanf("%d",&n);

	stack<char> opt,exp;

	while(n--)
	{
	
		while(!opt.empty())
			opt.pop();
		while(!exp.empty())
			exp.pop();

		char str[110];
		scanf("%s",str);
		char ch;
		
		int len = 0;
		while(str[len]!='\0')
			len++;
		
		for(int i = 0; i < len; i++)
		{
			ch = str[i];
			if(ch == '#')	
				break;
			
			if((ch >= 'a'&& ch <= 'z') || (ch >= 'A'&& ch <= 'Z') || (ch >= '0'&& ch <= '9'))
				exp.push(ch);
			else
			{
				if(ch == '(')
					opt.push(ch);
				else if(ch == ')')
				{
					while(opt.top()!='(')
					{
						exp.push(opt.top());
						opt.pop();
					}
					opt.pop();
				}
				else
				{
					if(opt.empty() || JudgeOpt(ch, opt.top()))
					{
						opt.push(ch);
					}
					else
					{
						exp.push(opt.top());
						opt.pop();
						while(!opt.empty())
						{
							if(JudgeOpt(opt.top(), ch))
							{
								exp.push(opt.top());
								opt.pop();
							}
							else
								break;
						}
						opt.push(ch);
					}
				}
			}

		}
		while(!opt.empty())
		{
			exp.push(opt.top());
			opt.pop();
		}
		int num = 1;
		while(!exp.empty())
		{
			str[num++]=exp.top();
			exp.pop();
		}
		for(int i = num - 1; i > 0; i--)
		{
			printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}
