#include<stdio.h>
int main()
	{
		int w,d,y,m;
		if (scanf("%d%d%d",&y,&m,&d)==3);
		w=week(y,m,d);
	
		int d_days=total(y,m,d);

		int j=((d_days/91)%5);
		int num=information(j,w);
		
	}
int week(int y,int m,int d)
	{	
		int w;
		if (m==2||m==1) 
		{
			m=m+12;y--;
			w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
		if (m==13||m==14) 
			m=m-12;y++;
		}
		else 
		w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
		return(w);
	}
int total(int y2,int m2,int d2)
	{
		int y1,m1,d1,sum1,sum2,sum3=0,i,j,k;
		y1=2012;
		m1=4;
		d1=9;
		sum1=days(y1,m1,d1);
		sum2=days(y2,m2,d2);
		j=y2-y1;
		for(i=0;i<j;i++)
		{	
			k=year_days(y1+i);
			sum3=sum3+k;
		}
		return(sum2-sum1+sum3);
	}
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
	
	if  ( leap_year( year ) && month >2 )
		day++;
	
	for ( i=1; i<month; i++ )
		day += months[i];

	return day;
	}
int information(int j,int w)
	{		
			int i=0,k=0;
			int a[7][2]={{3,8},{4,9},{5,0},{1,6},{2,7},{0,0},{0,0}}	;			
			int b[7][2]={{2,7},{3,8},{4,9},{5,0},{1,6},{0,0},{0,0}}	;
			int c[7][2]={{1,6},{2,7},{3,8},{4,9},{5,0},{0,0},{0,0}}	;
			int d[7][2]={{5,0},{1,6},{2,7},{3,8},{4,9},{0,0},{0,0}}	;
			int e[7][2]={{4,9},{5,0},{1,6},{2,7},{3,8},{0,0},{0,0}}	;
				
		if(j==0)
			{
				i=a[w][0];
				k=a[w][1];
			}
		if(j==1)
			{
				i=b[w][0];
				k=b[w][1];
			}
		if(j==2)
			{
				i=c[w][0];
				k=c[w][1];
			}
		if(j==3)
			{
				i=d[w][0];
				k=d[w][1];
			}
		if(j==4)
			{
				i=e[w][0];
				k=e[w][1];
			}
		if(i==0 && k==0) printf("Free.\n");
		else printf("%d and %d.\n",i,k);
	}
