#include <stdio.h>
#define len 100000
int main() {
    long long a,b;
    long long c[len];
    scanf("%lld %lld", &a, &b);
 
    for(long long i = 0; i < a; i++) {
        long long cur;
        scanf("%lld", &cur);
        c[i] = b - cur; 
    }
 
    long long d = c[0];
    for(long long i = 1; i < a; i++) {
        if(c[i] > c[i - 1]) 
            d += c[i] - c[i - 1];
    } 
    printf("%lld\n", d);
    return 0;
}