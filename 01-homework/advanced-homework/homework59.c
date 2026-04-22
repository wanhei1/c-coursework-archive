#include <stdio.h>

int leap_year( int );
int year_days( int );
int days(int,int,int);
int leap_year( int year ) 
{
return ( (year%4==0 && year%100!=0) || year%400==0 ) ? 1 : 0;
}
int year_days(int year) 
{
return leap_year( year ) ? 366 : 365;
}
int days( int year, int month, int day ) 
{
int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, i;
if( leap_year( year ) && month >2 )
day++;
for( i=1; i<month; i++ )
day += months[i];
return day;
}
int main()
{
int syear,smonth,sday,eyear,emonth,eday;
int bdays;
int i;

scanf("%d %d %d",&syear,&smonth,&sday);
scanf("%d %d %d",&eyear,&emonth,&eday);
if((eyear-syear)==0)
bdays=days(eyear,emonth,eday)-days(syear,smonth,sday);
else if((eyear-syear)==1)
bdays=(year_days(syear)-days(syear,smonth,sday))+days(eyear,emonth,eday);
else if((eyear-syear)>1)
bdays=(year_days(syear)-days(syear,smonth,sday))+days(eyear,emonth,eday);
for(i=1;i<(eyear-syear);i++)
bdays=bdays+year_days(syear+i);
printf("%d days\n",bdays);
return 0;
}