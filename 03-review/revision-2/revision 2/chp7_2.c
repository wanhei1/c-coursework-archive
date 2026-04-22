#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
 
BiTree Search(BiTree p,int k)
{
    if(k<p->data)
	{
        if(p->lchild==NULL) return p;
        else return Search(p->lchild,k);
    }
    
	else
	{
        if(p->rchild==NULL) return p;
        else return Search(p->rchild, k);
    }
}
 
void Print(BiTree p,int s)
{
    if(p->lchild!= NULL) Print(p->lchild, s+1);
    
	for(int i=0;i<s;i++)
            printf("    ");
        
		printf("%d\n", p->data);
    
	if(p->rchild != NULL) Print(p->rchild, s+1);
}
 
void MidPrint(BiTree p)
{
    if(p->lchild!=NULL) MidPrint(p->lchild);
    
	printf(" %d",p->data);
    
	if(p->rchild!=NULL) MidPrint(p->rchild);
}
 
int main()
{
    int key;
    BiTree root=NULL;
    scanf("%d",&key);
    
	root=(BiTree)malloc(sizeof(BiTNode));
    root->data=key;
    root->lchild=NULL;
    root->rchild=NULL;
    
	while(scanf("%d",&key)&&key!=0)
	{
        BiTree p=Search(root,key);
        if(key<p->data)
		{
            p->lchild=(BiTree)malloc(sizeof(BiTNode));
            p->lchild->data=key;
            p->lchild->lchild=NULL;
            p->lchild->rchild=NULL;
        }
        
		else
		{
            p->rchild=(BiTree)malloc(sizeof(BiTNode));
            p->rchild->data=key;
            p->rchild->lchild=NULL;
            p->rchild->rchild=NULL;
        }
    }
    Print(root,0);
    printf("\n");
    
	MidPrint(root);
    printf("\n");
    return 0;
}
