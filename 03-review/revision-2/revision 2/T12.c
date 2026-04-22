#include <stdio.h> 
 #include <stdlib.h>
typedef struct
{  
    long int c;  
    long int d;  
} time;
time x[300010]; 
int comp(const void* a,const void* b)
{  
    return (*(time*)a).d-(*(time*)b).d;  
}  
int main()  
{  
    long int a,n;  
    scanf("%ld",&n);  
    for(long int i=0;i<n;i++)  
    {  
        scanf("%ld",&(x[i].c));  
        scanf("%ld",&(x[i].d));  
     }  
    qsort (x,n,sizeof(time),&comp); 
    a=1;  
    for(long int i=1,j=0;i<n;i++)
    {  
        if(x[i].c>=x[j].d)  
        {  
            a++;  
            j=i;  
        }  
    }   
    printf("%ld\n",a);       
    return 0;  
}  
