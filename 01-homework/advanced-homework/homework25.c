#include <stdio.h>
int
main()
{
float
c,f;
scanf("%f",&c);
f=32+c*1.8;
printf("摄氏温度=%.2f,转换为华氏温度=%.2f\n",c,f);
getch();
return
0;
}