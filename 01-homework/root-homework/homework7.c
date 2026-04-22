#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
int i, len;
char str[100];
gets(str);
len=strlen(str);
for (i = 0; i < len; i++)
if (isalpha(str[i]))
{
str[i] ^= 32;
}
puts(str);
return 0;
}