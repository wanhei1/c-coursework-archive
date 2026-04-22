#include <stdio.h>
#include <math.h>
int main()
{
	int a,b;
	float t1,t2,deg;
	scanf("%d %d",&a,&b);
	if (a>12)
	{
		t1=a-12;
	}
	else
	{
		t1=a;
	}
	t2=b*6;
	t1=t1*30+b*0.5;
	deg=fabs(t1-t2);
	if (deg>180)
	{
		deg=360-deg;
	}
	printf("At %d:%02d the angle is %.1f degrees.\n",a,b,deg);
}
