#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct NODE
{
	int data;
	struct NODE *lchild;
	struct NODE *rchild;
}node,*Tree;

int main()
{
	int n = 0;
	char str[100010], prefix[100010];
	int flag = 0;
	
	Tree bit, T;
	bit = (Tree)malloc(sizeof(node));
	bit->data = 0;
	bit->lchild = NULL;
	bit->rchild = NULL;

	cin >> n;
	while(n--)
	{
		memset(str, 0, sizeof(str));
		cin >> str;
		int len = strlen(str);

		if (flag == 1)
			continue;
		strcpy(prefix, str);

		T = bit;
		for (int i = 0; i < len; i++)
		{
			if (str[i] == '1')
			{
				if (T->lchild == NULL)
				{
					T->lchild = (Tree)malloc(sizeof(node));
					T = T->lchild;
					T->lchild = NULL;
					T->rchild = NULL;
					if (i == len - 1)
						T->data = 1;
					else
						T->data = 0;
				}
				else
				{
					if (T->lchild->data == 1 || i == len - 1)
					{
						flag = 1;
						break;
					}
					else
						T = T->lchild;
				}
			}
			else	
			{
				if (T->rchild == NULL)
				{
					T->rchild = (Tree)malloc(sizeof(node));
					T = T->rchild;
					T->lchild = NULL;
					T->rchild = NULL;
					if (i == len - 1)
						T->data = 1;
					else
						T->data = 0;
				}
				else
				{
					if (T->rchild->data == 1 || i == len - 1)
					{
						flag = 1;
						break;
					}
					else
						T = T->rchild;
				}
			}
		}
	}
	if (flag == 0)
		cout << "YES" << endl;
	else
		cout << prefix << endl;

	return 0;
}
