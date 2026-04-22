#include <stdio.h>
 #define MAX 100
#define leap(y) (y%4==0 && y%100!=0 || y%400==0) 
struct date
{
    int y;
    int m;
     int d;
 };
long days(struct date d1,struct date d2)//d1 是起始日期，d2  是终止日期
{
    int mon[2][13]= {{0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}};
    int i; long td=0;
     for(i=d1.y;i<d2.y;i++)
         td+=leap(i)?366:365;
     for(i=1;i<d1.m;i++)
         td-=mon[leap(d1.y)][i];
     td-=d1.d-1;
     for(i=1;i<d2.m;i++)
         td+=mon[leap(d2.y)][i];
     td+=d2.d-1;
     return td;        //td就是两个日期之间的天数
 }
 
 int main()
 {
     struct date now[MAX],start={1990,1,1};
     int n,i,day;
     scanf("%d",&n);
     for(i=0;i<n;++i)
     {
         scanf("%d%d%d",&now[i].y,&now[i].m,&now[i].d);
     }
     for(i=0;i<n;++i)
     {
         day=days(start,now[i]);
         if(day%5<3)
                     printf("He was fishing on %d.%d.%d\n",now[i].y,now[i].m,now[i].d);
         else
             printf("He was basking on %d.%d.%d\n",now[i].y,now[i].m,now[i].d);
     }
     return 0;
 }