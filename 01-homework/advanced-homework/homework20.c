#include<stdio.h>  
int main()  
{   
    int i, j, m;  
    scanf("%d", &m);  
    for(i = 1; i <= m; i++)  
    {  
        for(j = 1 ;j <= 2*m-i; j++)  
        {
            if( j== i||i == 1||j == 2*m-i)  
                printf("*");  
            else 
                printf(" ");  
        }  
     printf("\n");       
    }  
    return 0;  
}  

