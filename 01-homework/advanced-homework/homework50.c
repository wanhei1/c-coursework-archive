#include<stdio.h>

#include<string.h>

int main()

{

char a[100][100],c,ch;

int n,i,j;

memset(a,' ',sizeof(a));

scanf("%d %c",&n,&ch);

for(i=0;i<n;i++)

{

a[i][i] = a[i][2*n-2-i] = ch++;

if(ch>'Z')

{

ch = 'A';

}

}

for(i=1;i<n;i++)

{

a[n-1][n-1-i] = a[n-1][n-1+i] = ch++;

if(ch>'Z')

{

ch = 'A';

}

}

for(i=n-2;i>0;i--)

{

a[i][0] = a[i][2*n-2] = ch++;

if(ch>'Z')

{

ch = 'A';

}

}

for(i=0;i<n;i++)

{

printf("%c",a[i][0]);

for(j=1;j<2*n-1;j++)

{

printf(" %c",a[i][j]);

}

printf("\n");

}

return 0;

}