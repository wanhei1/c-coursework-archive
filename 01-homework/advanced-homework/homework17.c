#include<stdio.h>
int main()

{
int i, j, k, a, b, c, d, m=0, e;

for( e = 0 ; e >= 0 ; e++)

{
scanf("%d%d",&i,&j);

if( i == 0 || j == 0 ) break;

else

if( ( i > 9999 || i < 1000 ) || ( j > 9999 || j < 1000 ) )

printf("Error\n");

else

{
for( k = i ; k <= j ; k++)

{
if ( k % 2 == 1) continue;

a = k / 1000;

b = ( k % 1000 ) / 100;

c = ( k % 100 ) / 10;

d = k % 10;

if( a == b || a == c || a == d || b == c || b == d || c == d ) continue;

printf("%d  ",k);

m += 1;

}

printf("\ncounter=%d\n",m);

m=0;

}

}

return 0;

}