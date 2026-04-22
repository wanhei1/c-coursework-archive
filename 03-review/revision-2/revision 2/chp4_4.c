#include<stdio.h>  
#include<string.h>  
typedef struct{  
    int i, j;  
    int e;  
}Trip;  
typedef struct{  
    Trip data[1000];  
    int rpos[1000];  
    int mu, nu, tu;  
}Matrix;  
int main()  
{  
    int i;  
    int arow;  
    int tp;  
    int p;  
    int brow;  
    int t;  
    int q;  
    int ccol;  
    int ctemp[1000];  
    int num[1000];  
    int col;  
    Matrix A, B, Q;  
    scanf("%d%d%d", &A.mu, &A.nu, &A.tu);  
    for (i = 1; i <= A.tu; i++)  
        scanf("%d%d%d", &A.data[i].i, &A.data[i].j, &A.data[i].e);  
    scanf("%d%d%d", &B.mu, &B.nu, &B.tu);  
    for (i = 1; i <= B.tu; i++)  
        scanf("%d%d%d", &B.data[i].i, &B.data[i].j, &B.data[i].e);  
    for (col = 1; col <= A.mu; col++)  
        num[col] = 0;  
    for (i = 1; i <= A.tu; i++)  
        num[A.data[i].i]++;  
    A.rpos[1] = 1;  
    for (col = 2; col <= A.mu; col++)  
        A.rpos[col] = A.rpos[col - 1] + num[col - 1];  
    for (col = 1; col <= B.mu; col++)  
        num[col] = 0;  
    for (i = 1; i <= B.tu; i++)  
        num[B.data[i].i]++;  
    B.rpos[1] = 1;  
    for (col = 2; col <= B.mu; col++)  
        B.rpos[col] = B.rpos[col - 1] + num[col - 1];  
    Q.mu = A.mu;  
    Q.nu = B.nu;  
    Q.tu = 0;  
    if (A.tu*B.tu != 0){  
        for (arow = 1; arow <= A.mu; arow++){  
            memset(ctemp, 0, sizeof(ctemp));  
            Q.rpos[arow] = Q.tu + 1;  
            if (arow < A.mu)  
                tp = A.rpos[arow + 1];  
            else  
            {  
                tp = A.tu + 1;  
            }  
            for (p = A.rpos[arow]; p < tp; p++){  
                brow = A.data[p].j;  
                if (brow < B.mu)  
                    t = B.rpos[brow + 1];  
                else  
                {  
                    t = B.tu + 1;  
                }  
                for (q = B.rpos[brow]; q < t; q++){  
                    ccol = B.data[q].j;  
                    ctemp[ccol] += A.data[p].e*B.data[q].e;  
                }  
            }  
            for (ccol = 1; ccol <= Q.nu;ccol++)  
            if (ctemp[ccol]){  
                Q.tu++;  
                Q.data[Q.tu].i = arow;  
                Q.data[Q.tu].j = ccol;  
                Q.data[Q.tu].e = ctemp[ccol];  
            }  
        }  
    }  
    printf("%d\n", Q.mu);  
    printf("%d\n", Q.nu);  
    printf("%d\n", Q.tu);  
    for (i = 1; i <= Q.tu; i++)  
        printf("%d,%d,%d\n", Q.data[i].i, Q.data[i].j, Q.data[i].e);  
    return 0;  
}