#include<stdio.h>  
#include<stdlib.h>  
#define MAX 11  
int record[MAX]={0};  
  
int comp(const void *a,const void *b)  
{  
    return *(int*)a-*(int*)b;  
}  
typedef struct{  
    int d;  
    int num_of_link;  
    int linkto[MAX];  
}node;  
  
node dot[MAX];  
  
void bfs(int pt)  
{  
    int f=1; 
    int n=0;  
    qsort(dot[pt].linkto,dot[pt].num_of_link,sizeof(int),comp);  
    for(int i=0;i<dot[pt].num_of_link;++i)  
    {  
        if(dot[dot[pt].linkto[i]].d==0)  
        {  
            f=0;   
            printf("-%d",dot[pt].linkto[i]);  
            dot[dot[pt].linkto[i]].d=1;  
            record[n]=dot[pt].linkto[i];  
            ++n;  
        }  
    }  
    if(f) return;  
    for(int i=0;i<n;++i)  
    {  
        bfs(record[i]); 
    }  
    return;  
}  
  
int main()  
{  
    int n;  
    scanf("%d",&n);  
    for(int i=0;i<n;++i)  
    {  
        dot[i].d=0;  
        dot[i].num_of_link=0;  
    }  
    int f,t;  
    while(1)  
    {  
        scanf("%d",&f);  
        if(f==-1) break;  
        scanf("%d",&t);  
        dot[f].linkto[dot[f].num_of_link]=t;  
        ++dot[f].num_of_link;  
        dot[t].linkto[dot[t].num_of_link]=f;  
        ++dot[t].num_of_link;  
    }  
    for(int i=0;i<n;++i)  
    {  
        if(dot[i].d==0)  
        {  
            dot[i].d=1;  
            printf("%d",i);  
            bfs(i);  
            printf("\n");  
        }  
    }  
    return 0;  
}  