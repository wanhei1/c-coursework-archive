#include<stdio.h>
struct s1
{

char a[3];
int num;
} t = { 'a', 'b', 'c', 4 }, *p;
p = &t;
printf( "%c\n",p->t.a[2] );