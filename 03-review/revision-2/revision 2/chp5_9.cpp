
#include <cstdbool>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

int m = 0;
int n = 0;
int tot = 0;  
int* row = NULL;  
int* column = NULL;  
int* slash = NULL;  
int* reslash = NULL; 

int judge()
{ 
    int i, j;

    for(i = 1; i <= n; i++) {

        if(row[i] == 999) { 
            for(j = 1; j <= n; j++) {
                if(column[j] == 999) { 
                    if(!(reslash[i + j] == 1 || slash[n + i - j + 1] == 1)) { 
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

void traceback(bool flag, int level, int num)
{      if(level > n) {
        if(num != m) 
            return;
        if(judge())
            tot++;
        return;
    }

    if(n - level + num < m) 
        return;
    if(!flag) {
        traceback(false, level + 1, num);
        traceback(true, level + 1, num + 1);
    }
    else {
        for(register int i = 1; i <= n; i++) {
            
						if(column[i]==999&&reslash[level+i]==999&&slash[n+level-i+1]==999)
            {
                row[level] = level; 
                column[i] = i; 
                reslash[level + i] = 1;
                slash[n + level - i + 1] = 1;
                traceback(false, level + 1, num);
                traceback(true, level + 1, num + 1);
	
                row[level] = 999;
                column[i] = 999;
                reslash[level + i] = 999;
                slash[n + level - i + 1] = 999;
            }
        }
    }
}

int main()
{
    cin >> n;
    cin >> m;

    column = new int[n + 1];
    row = new int[n + 1];
    slash = new int[2 * n + 1];
    reslash = new int[2 * n + 1];

    for(register int i = 0; i <= n; i++) {
        column[i] = 999;
        row[i] = 999;
    }
    for(register int i = 0; i < 2 * n + 1; i++) {
        slash[i] = 999;
        reslash[i] = 999;
    }

    traceback(false, 1, 0); 
    traceback(true, 1, 1); 
    cout << tot << endl;

    return 0;
}
