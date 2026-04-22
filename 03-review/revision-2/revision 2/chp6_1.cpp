#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct Node{
	char data;
    int f,Near[500],n;
}List[500];
int main()
{
	int i = 0;
	int j;
	int count_point;
	int lpoint, rpoint;
	char temp[5];
	queue <Node> T;
	while (1){
		scanf("%s", temp);
		if (temp[0] == '*')
			break;
		List[i].data = temp[0];
		List[i].f = 0;
		List[i].n = 0;
		i++;
	}
	count_point = i;
	while (1){
		scanf("%d,%d", &lpoint, &rpoint);
		if (lpoint == -1 && rpoint == -1)
			break;
		List[lpoint].Near[List[lpoint].n] = rpoint;
		List[lpoint].n++;
		List[rpoint].Near[List[rpoint].n] = lpoint;
		List[rpoint].n++;
	}
	printf("the ALGraph is\n");
	for (i = 0; i < count_point; i++){
		printf("%c", List[i].data);
		for (j = List[i].n - 1; j >= 0; j--)
			printf(" %d", List[i].Near[j]);
		printf("\n");
	}
	printf("the Breadth-First-Seacrh list:");
	for (i = 0; i < count_point; i++){
		if (List[i].f == 0){
			T.push(List[i]);
			List[i].f = 1;
			struct Node now;
			while (!T.empty()){
				now = T.front();
				printf("%c", now.data);
				for (j = now.n - 1; j >= 0; j--){
					if (List[now.Near[j]].f == 0){
						List[now.Near[j]].f = 1;
						T.push(List[now.Near[j]]);
					}
				}
				T.pop();
			}
		}
	}
	printf("\n");
	return 0;
}