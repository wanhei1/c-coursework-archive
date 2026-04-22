#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>   
int v, arcnum,topo[55], path[100];   
struct link  
{  
    int d,w;
};  
struct vex  
{  
    char name[5];  
    int inNum = 0; 
    int outNum = 0; 
    int ve, vl; 
    link linkTo[300];  
    int linkNum = 0;  
};  
  
vex node[50];  
  
  
int comp(const void*a,const void*b)  
{  
    return *(int*)a-*(int*)b; 
}   
  
int comp2(const void*a,const void*b)  
{  
    return *(int*)b-*(int*)a;
}   
void CreateGraph()  
{  
    char str[500] = { '\0' };  
    scanf("%s",str);  
    int len = strlen(str), q = 0, k = 0;  
    for (int i = 0; i < len; i++)  
    {  
        if (str[i] != ',')  
            node[k].name[q++] = str[i];  
        else  
        {  
            node[k].name[q] = '\0';  
            k++;  
            q = 0;  
        }  
    }  
    getchar();  
      
    int a,b,c;  
    for(int i=0;i<arcnum;++i) 
    {  
        scanf("<%d,%d,%d>",&a,&b,&c);  
        node[b].inNum++;  
        node[a].outNum++;  
        node[a].linkTo[node[a].linkNum].dir=b;  
        node[a].linkTo[node[a].linkNum].weight=c;  
        node[a].linkNum++;  
        getchar();    
    }  
      
    for (int i = 0; i < v; i++) 
        qsort(node[i].linkTo, node[i].linkNum, sizeof(node[i].linkTo[0]), comp);
}  
int TopoLogicalSort_DFS()  
{  
    int *Stack, u, v, top = 0, count = 0;  
    Stack = (int*)malloc(sizeof(int) * v);   
    for (int i = 0; i < v; i++)
    {  
        node[i].ve = 0;   
        if (node[i].inNum == 0) Stack[top++] = i;  
    }  
    while (top > 0)  
    {  
        u = Stack[--top]; 
        topo[count++] = u;  
  
        for (int i = 0; i <= node[u].linkNum; i++)
        {  
            int v = node[u].linkTo[i].dir;  
            if (node[v].ve < node[u].ve + node[u].linkTo[i].weight)  node[v].ve = node[u].ve + node[u].linkTo[i].weight;  
            if (--node[v].inNum == 0)   Stack[top++] = v;  
        }  
        qsort(Stack, top, sizeof(Stack[0]), comp2);
    }  
    free(Stack);  
    return (count == v) ? 1 : 0;   
}  
  
void PrintPath(int top, int end)  
{  
    int u = path[top - 1];  
    if (u == end)  
    {  
        printf("%s", node[path[0]].name); 
        for (int i = 1; i < top; i++)  
            printf("-%s", node[path[i]].name);  
        printf("\n");  
        return;  
    }  
    for (int i = 0; i <= node[u].linkNum; i++)  
    {  
        int v = node[u].linkTo[i].dir;  
        if (node[u].ve + node[u].linkTo[i].weight < node[v].ve)  continue;  
        if (node[v].ve == node[v].vl)
        {  
            path[top++] = node[u].linkTo[i].dir;
            PrintPath(top, end);
            top--;
        }  
    }
    return 0;
  
}  
  
/*求关键路径*/  
void CriticalPath()  
{  
    if (!TopoLogicalSort_DFS())  
    {  
        printf("NO TOPOLOGICAL PATH\n");  
        return;  
    }  
    for (int i = 0; i < v; i++)  
    {  
        node[i].vl = node[v - 1].ve; //初始化各事件最晚发生事件为最后一个事件发生的时间   
        if (i)  printf("-");  
        printf("%s", node[topo[i]].name); //打印拓扑序列  
    }  
    printf("\n");  
    for (int i = v - 2; i >= 0; i--)  
    {  
        int u = topo[i];  
        for (int j = 0; j <= node[u].linkNum; j++)  
        {  
            int v = node[u].linkTo[j].dir;  
            if (node[u].vl > node[v].vl - node[u].linkTo[j].weight)  node[u].vl = node[v].vl - node[u].linkTo[j].weight;  
        }  
    }  
    path[0] = topo[0];  
    PrintPath(1, topo[v - 1]);  
}  
  
int main()  
{  
    scanf("%d,%d", &v, &arcnum);  
    CreateGraph();//把顶点和边信息读入到表示图的邻接表中   
    CriticalPath();//求关键路径  
    return 0;  
}  