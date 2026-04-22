#include <stdio.h>  
#include <stdlib.h>
typedef struct{  
    long long int x,y,z;  
    
} hp_dragon;
hp_dragon xp1[200005]={},xp2[200005]={};  
  
int comp(const void* a,const void* b){  
    return (*(hp_dragon*)a).x-(*(hp_dragon*)b).x;  
}  
  
int comp2(const void* a,const void* b){  
    return (*(hp_dragon*)b).z-(*(hp_dragon*)a).z;  
}  
int main()  
{  
    long int n;  
    long long int j=0,k=0,A=0,c,d,m=0;
    scanf("%ld",&n);  
    for(long int i=1;i<=n;i++)  
    {  
        scanf("%lld",&c);  
        scanf("%lld",&d);  
        if(d>=0)  
            {  
                xp1[j].x=c;  
                xp1[j].y=d;  
                j++;      
            }  
        else  
            {  
                xp2[k].x=c;  
                xp2[k].y=d;   
                xp2[k].z=c+d;  
                k++;  
            }  
    }
    qsort (xp1,j,sizeof(hp_dragon),&comp);   
    qsort (xp2,k,sizeof(hp_dragon),&comp2);   
    for(long int i=0;i<j;i++)  
    {  
        if(A>=xp1[i].x)  
            {  
                A=A+xp1[i].y;  
            }     
        else  
            {  
                m=m+xp1[i].x-A;  
                A=xp1[i].x;  
                A=A+xp1[i].y;      
            }  
    } 
    for(long int i=0;i<k;i++)  
    {  
        if(A>=xp2[i].x)  
        {  
            A=A+xp2[i].y;  
        }  
        else  
        {  
            m=m+xp2[i].x-A;  
            A=xp2[i].x;  
            A=A+xp2[i].y;  
        }  
    }
    printf("%lld\n",m);  
    return 0;  
}