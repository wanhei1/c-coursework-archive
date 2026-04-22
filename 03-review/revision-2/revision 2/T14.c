#include <stdio.h>
#include <stdlib.h>
typedef struct{
	long long int a;
	long long int b;
	long long int c;
	int number;
}
 cube;

cube x1[100010],x2[100010];
int comp(const void* a,const void* b)
{
	return (*(cube*)b).c-(*(cube*)a).c;
}

int comp2(const void* e,const void* f)
{
	return (*(cube*)f).b-(*(cube*)e).b;
}
int main()
{
	long int n;
	long long int x3[3]={};
	scanf("%ld",&n);
	for(long int i=0;i<n;i++)
		{
			scanf("%lld",&x3[0]);
			scanf("%lld",&x3[1]);
			scanf("%lld",&x3[2]);
			long long int m;
			for(int p=1;p<=2;p++)
				{
					for(int i=0;i<3-p;i++)
						{
							if(x3[i]>x3[i+1])
								{
									m=x3[i];
									x3[i]=x3[i+1];
									x3[i+1]=m;
								}
						}
				}
			x1[i].c=x3[0];
			x1[i].b=x3[1];
			x1[i].a=x3[2];
			x1[i].number=i;
		}
	qsort (x1,n,sizeof(cube),&comp);
	long int l=0;
	long long int max1=0;
	max1=x1[0].c;
	for(long int i=0;i<n;i++)
	{
		if(x1[i].b<max1)
		{
			continue;
		}
		else
		{
			x2[l].a=x1[i].a;
			x2[l].b=x1[i].b;
			x2[l].c=x1[i].c;
			x2[l].number=x1[i].number;
			l++;
		}
	}
	long int o,p;
	long long int m2=0,w=0;
	qsort (x2,l,sizeof(cube),&comp2);
	for(long int i=0;i<l-1;i++)
	{
		if(x2[i].a==x2[i+1].a&&x2[i].b==x2[i+1].b)
			{
				w=x2[i].c+x2[i+1].c;
				if(w>x2[i+1].b)
				{
					w=x2[i+1].b;
				}
				if(w>m2)
				{
					m2=w;
					o=i;p=i+1;
				}
			}
	}
	if(max1>m2)
	{
		printf("1\n");
		printf("%ld\n",x1[0].number+1);
	}
	else
	{
		printf("2\n");
		printf("%ld %ld\n",x2[o].number+1,x2[p].number+1);
	}
	return 0;
}



