
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
} ;
 
typedef struct node NODE;
typedef struct node * PNODE;
 
 
 
int outlist( PNODE head )
{
    PNODE p;
    p = head->next;
    while ( p != NULL )
    {
        printf("%d\n", p->data);
        p = p->next;
    }
	return 1;
}
 void ins_list( PNODE h, int num )
{
	
    NODE  * r,* p;
	r=h;
	while(r->next!=NULL)
	{
		r=r->next;
	}
    p=(PNODE)malloc(sizeof(NODE));
    p->data=num;
	p->next=NULL;//p为待插结点
	if(h->next==NULL)
	{
		
		h->next=p;
		r=p;
	}
	else
	{
		r->next=p;
	    r=r->next;
	}
 
}
int main ( )
{
    int num=1;
    PNODE head;
 
    head = (PNODE)malloc( sizeof(NODE) );
    head->next = NULL;
    head->data = -1;//建立头结点
 
    while ( num!=0 )
    {
        scanf("%d", & num);
        if ( num!=0 )
            ins_list( head, num);//插入算法
    }
    outlist( head );
    return 1;
}