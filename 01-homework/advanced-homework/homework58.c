#include <stdio.h>
int reverse(char str[],int start,int end);
int main( )
{ char str[100];
int start, end;
gets(str);
scanf("%d%d", &start, &end);
reverse( str, start, end );
printf("%s\n", str);
return 0;
}
int reverse(char str[],int start,int end)
{
if(start==end||(start-end==1))
{return 1;} 
else
{str[start]=str[start]+str[end];
str[end]=str[start]-str[end];
str[start]=str[start]-str[end];
return reverse(str, start+1,end-1);}
}