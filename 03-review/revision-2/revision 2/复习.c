/*创建链表*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    char name[20],address[20],phone[15];
    struct node *link /*定义node型结构指针*/
};
typedef struct node NODE /*定义结点类型*/
 main(){
NODE * head; /*说明头指针*/

NODE*p;
p=(NODE*)malloc(sizeof(NODE)); /*申请存储空间建立表头结点*/
p-> link=NULL; 
head=p;
int create(NODE*head,int n);
create(head,2);
int  insert_node(NODE*head,NODE*p,int i);
 
p=(NODE*)malloc(sizeof(NODE));
gets(p->name);
insert_node(head,p,1);

int output(NODE*head);
output(head);

int delete_node (NODE*head,int i);
delete_node(head,2);

getchar();
}
/*插下一个数据结点*/
int create(NODE*head,int n)
{ NODE*p;
for(;n>0;n--){
p=(NODE*)malloc(sizeof(NODE));
gets(p->name);gets(p->address);gets(p->phone);/*按照访问结构的方法，将数据存入p指向的结点*/
p->link=head->link;/*头结点的link存入p的link中*/
head->link=p;/*数据结点p插在头结点后*/
}
return 0;
}
/*访问所有数据结点点*/
int output(NODE*head)
{
    NODE * p;
    p= head->link;/*p指向第一个数据结点*/
    while(p!=NULL)
    {
        puts(p->name);/*输出p指向结点的数据*/
        p=p->link;/*p指向下一个数据结点*/
    }
    return 0;
}
/*链表长度*/
length (NODE *head)
{int len;
NODE*p;
for(len=0;p=head->link;p!=NULL;++len)
p=p->link;
return(len);}
/*插入新结点，q指向第i个结点，p需要插入的结点*/
int insert_node (NODE * head ,NODE *p int i)
{
    NODE *q;
    int n=0;
    for (q=head;n<i&&q->link!=NULL;++n)
    q=q->link;
    p->link=q->link;
    q->link=p;
    return 0;
}
/*删除结点，q-》i-1，p被删除*/
int delete_node (NODE*head,int i){
    NODE*q,*p;
    int n;
    for(n=0,q=head;n<i-1&&q->link!=NULL;++n)
    q=q->link;
    if(i>0&&q->link !=NULL)
    {
        p=q->link;
        q->link=p->link;
        free(p);
    }
}