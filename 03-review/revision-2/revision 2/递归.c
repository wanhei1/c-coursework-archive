#include <stdio.h>    
long long findf(int n) 
{  
    if (n <= 0) return 1;  
    else return n * findf(n - 1) + findf(n - 2);  
}   
int main () 
{  
    int n;  
    scanf("%d", &n);  
    printf("%lld\n", findf(n));  
    return n;  
}