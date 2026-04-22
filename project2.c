
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h>

  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
void output( NODE *, int );  
void change( int, int, NODE * );  
  
void output( NODE * head, int kk )  
{   int k=0;  
  
    printf("0.");  
    while ( head->next != NULL && k<kk )  
    {   printf("%d", head->next->data );  
        head = head->next;  
        k ++;  
    }  
    printf("\n");  
}  
  
int main()  
{   int n, m,k;  
    NODE * head;  
  
    scanf("%d%d%d", &n, &m, &k);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    change( n, m, head );  
    output( head,k );  
    return 0;  
}  
void change(int n, int m, NODE *head )
{
	
    int shang[10010], yushu[10010];
    memset(shang, 0, sizeof(shang));
    memset(yushu, 0, sizeof(yushu));
    int p1 = 0, p2 = 0;
    int flag = 0;
    int num = n * 10;

    for (int i = 0; ; i++)
    {
    	shang[i] = num / m;
    	yushu[i] = num % m;

    	for (int j = 0; j < i; j++)
    	{
    	  		
    		if(shang[j] == shang[i] && yushu[j] == yushu[i])
    		{
    			p1 = j;
    			p2 = i;

    			flag = 1;
    			break;
    		}
    	}
    	num = yushu[i] * 10;

    	if(!num)
    	{
    		p1 = i + 1;
    		break;
    	}
    	if(flag == 1)
    	{
    		break;
    	}
    }
    
    NODE *r = head;
    for (int i = 0; i < p1; i++)
    {
    
    	NODE *q = (NODE*)malloc(sizeof(NODE));
    	q->data = shang[i];
    	q->next = NULL;
    	r->next = q;
    	r = q;
    }

    if (flag == 1)
    {
    	NODE *r_save = r;
    	for (int i = p1; i < p2; i++)
    	{
    		NODE *q = (NODE*)malloc(sizeof(NODE));
    		q->data = shang[i];
    		q->next = NULL;
    		r->next = q;
    		r = q;
    	}
    	r->next = r_save->next;
    }
}
