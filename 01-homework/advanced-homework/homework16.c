#include <stdio.h>
int main()
{
	int year,day,leapyear=0,i,whichday;
	scanf("%d",&year);
	for(i=1900;i<=year;i++)
	{
	   if((i%400==0)||((i%100!=0)&&(i%4==0)))leapyear+=1;
    }
	day=(((year-1899)*365+leapyear)-(31+30+31+31+30+31+30+31))%7;
	if(day==7)whichday=14;
	else whichday=14-day;
	printf("%d\n",whichday);
	return 0;
}