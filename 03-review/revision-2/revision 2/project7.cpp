#include<iostream>
#include<memory>
using namespace std;
const int Max = 100;
class Graph
{
private:
	int N;
	int A, B, C;
	int V[Max][Max];
public:
	Graph(int n)
	{
		N = n;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> V[i][j];
			}
		}
		A = B = C = 1;
	}
	void ConnectedJudge()//基于Kosaraju算法
	{
		bool visited1[Max] = { 0 };
		DFS(0, visited1, V);
		for (int i = 0; i < N; i++)
		{
			if (visited1[i] == false)
			{
				A = 0;
				break;
			}
		}
		int reverse[Max][Max];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				reverse[i][j] = V[j][i];
			}
		}
		bool visited2[Max] = { 0 };
		DFS(0, visited2, reverse);
		for (int i = 0; i < N; i++)
		{
			if (visited2[i] == false && visited1[i] == false)
			{
				B = 0;
				break;
			}
		}
	}
	void DFS(int x, bool visited[], int t[][Max])
	{
		if (visited[x] == true)
			return;
		visited[x] = true;
		for (int i = 0; i < N; i++)
		{
			if (t[x][i] > 0)
				DFS(i, visited,t);
		}
	}
	void Print()
	{
		if (A == 1)
		{
			cout << "A" << endl;
		}
		else if (B == 1)
		{
			cout << "B" << endl;
		}
		else
		{
			cout << "C" << endl;
		}
	}
};
int main()
{
	int n;
	cin >> n;
	Graph G(n);
	G.ConnectedJudge();
	G.Print();
	return 0;
}
