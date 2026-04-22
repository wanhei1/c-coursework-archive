#include<bits/stdc++.h>  
using namespace std;

int vexnum;
int edgenum;
char sourceNode;

int** matrix = NULL; 

int CtoI(char ch)
{
    return ch - 'a' + 1;
}

char ItoC(int i)
{
    return i - 1 + 'a';
}

void CreateGraph()
{
    int i, j;
    char start;
    char end;
    int weight;
   
    matrix = new int*[vexnum + 1];
    for(i = 0; i <= vexnum; i++) {
        matrix[i] = new int[vexnum + 1];
    }
   
    for(i = 1; i <= vexnum; i++) {
        for(j = 1; j <= vexnum; j++)
            matrix[i][j] = INT_MAX;  
        matrix[i][i] = 0; 
    }
   
    int k = 1;
    while(k <= edgenum) {
        scanf("<%c,%c,%d>", &start, &end, &weight);
        getchar();

       
        i = CtoI(start);
        j = CtoI(end);
        matrix[i][j] = weight; 
        k++;
    }
}
void Floyd()
{
    int i, j, k;
    for(k = 1; k <= vexnum; k++) {
        for(i = 1; i <= vexnum; i++) {
            for(j = 1; j <= vexnum; j++) {
                if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                    continue; 
                if(matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
}

void Output()
{
    for( int i = 1; i <= vexnum; i++) {
        for( int j = 1; j <= vexnum; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Print(int i)
{
    for( int j = 1; j <= vexnum; j++) {
        cout << ItoC(j) << ":" << matrix[i][j] << endl;
    }
}

int main()
{
   
    scanf("%d,%d,%c", &vexnum, &edgenum, &sourceNode);
    getchar();

    CreateGraph();
    Floyd();
   
    Print(CtoI(sourceNode));

    return 0;
}
