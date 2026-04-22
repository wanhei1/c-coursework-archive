#include <stdio.h>  
int main()
{
    int a,b,result;
    char ch;
    scanf("%d%c%d",&a,&ch,&b);
    switch (ch)
    {
    case '+':
        result=a+b;
        break;
    case'-':
        result=a-b;
    break;
    case'*':
    result=a*b;
    break;
    case'/':
    result=a/b;
    break;
    default:
        break;
    }
    printf("%d\n",result);
    return 0;
}