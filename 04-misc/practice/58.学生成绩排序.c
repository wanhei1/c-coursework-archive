#include<string.h>
#include <stdio.h>
#include <stdlib.h>
struct nn
{  
	char name[21];
	int  grade;
};

typedef struct nn DATA;

int main( )
{
	char ch,str[21];
	DATA b[100];
	int i,j,n,temp;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
		memset(b[i].name,'\0',sizeof(b[i].name));
	for(i=0,j=0;i<n;i++,j=0)
	{
        ch = getchar();
        while(ch!=',')
        {
            b[i].name[j++] = ch;
            ch = getchar();
        }
        scanf("%d",&b[i].grade);
		getchar();
	}
	
	for(i=0;i<n-1;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(b[j].grade>b[j-1].grade)
			{
				temp = b[j].grade;
				b[j].grade = b[j-1].grade;
				b[j-1].grade = temp;
				strcpy(str,b[j].name);
				strcpy(b[j].name,b[j-1].name);
				strcpy(b[j-1].name,str);
			}
		}
	}
	for ( i=0; i<n; i++ )
		printf("%s,%d\n", b[i].name, b[i].grade );
	return 0;
}