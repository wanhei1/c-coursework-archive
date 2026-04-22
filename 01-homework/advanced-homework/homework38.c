#include <stdio.h>
int main()
{
	int month[10];
	int a[13]={0,12,43,71,102,132,163,193,224,255,285,316,346};
	int b[13]={0,12,43,72,103,133,164,194,225,256,286,317,347};
	int n=0,i,year;
	scanf("%d",&year);
	if(((year%4==0)&&(year%400!=0))||(year%100==0))
	{
		for(i=1;i<=12;i++)
		{
			if((year*365+(year-1)/4-year/100+year/400+b[i])%7==5)
			{
				month[n]=i;
				n++;
			}
		}
	}
	else
	{
		for(i=1;i<=12;i++)
		{
			if((year*365+year/4-year/100+year/400+a[i])%7==5)
			{
				month[n]=i;
				n++;
			}
		}
	}
	if(n==0)
	{
		printf("There is %d Black Friday in year %d.\n",n,year);
	}else
	{
		if(n==1)
		{
			printf("There is %d Black Friday in year %d.\nIt is:\n",n,year);
			printf("%d/%d/%d\n",year,month[0],13);
		}
		else
		{
			printf("There are %d Black Fridays in year %d.\nThey are:\n",n,year);
			for(i=0;i<n;i++)
			printf("%d/%d/%d\n",year,month[i],13);
		}
	}
		return 0;
}