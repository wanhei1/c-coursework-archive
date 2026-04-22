#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<math.h>  
  
typedef struct BiTree  
{  
    char d;  
    struct BiTree* r;  
    struct BiTree* l;  
}BT;  
  
int leafnum;  
  
BT* creatnode(char d)  
{  
    BT* p=NULL;  
    p=(BT*)malloc(sizeof(BT));  
    p->d=d;  
    p->l=NULL;  
    p->r=NULL;  
    return p;  
}  
  
char t[200]; 
int level=0,depth=0; 
int creatBiTree(BT* root,int sum)  
{  
    double q=(double)sum;  
    depth=ceil(log(q)/log(2));  
    if(depth>level)   
    {  
        depth--;  
        return 0;  
    }  
    char ltemp,rtemp;  
    //left  
    ltemp=t[2*sum-1];  
    rtemp=t[2*sum];  
  
    if(ltemp=='#'||ltemp=='\0')  
        root->l=NULL;  
    else  
    {  
        root->l=creatnode(ltemp);  
        creatBiTree(root->l,2*sum);  
    }  
    //right    
    if(rtemp=='#'||rtemp=='\0')  
    root->r=NULL;  
    else  
    {  
        root->r=creatnode(rtemp);  
        creatBiTree(root->r,2*sum+1);  
    }  
    return 0;  
  
}  
  
int printtree(BT* root,int rank)  
{  
    if(root==NULL)  
        return 0;  
    for(int i=0;i<rank;i++)  
        printf("    ");  
    printf("%c\n",root->d);  
    printtree(root->l,rank+1);  
    printtree(root->r,rank+1);  
    return 0;  
}  
  
int printperorder(BT* head)  
{  
    if(head==NULL)  
        return 0;  
    printf("%c",head->d);  
    printperorder(head->l);  
    printperorder(head->r);  
    return 0;  
}  
  
int printinorder(BT* head)  
{  
    if(head==NULL)  
        return 0;  
    printinorder(head->l);  
    printf("%c",head->d);  
    printinorder(head->r);  
    return 0;  
}  
  
int printpostorder(BT* head)  
{  
    if(head==NULL)  return 0;  
    printpostorder(head->l);  
    printpostorder(head->r);  
    printf("%c",head->d);  
    return 0;  
}  
  
int countleaf(BT* head)  
{  
    if(head->l==NULL&&head->r==NULL)  
        leafnum++;  
    if((head->l))  
        countleaf(head->l);  
    if((head->r))  
        countleaf(head->r);  
    return 0;  
}  
  
BT* swap(BT* head)  
{  
    BT* p=NULL;  
    if(head==NULL)  return NULL;  
    p=head->l;  
    head->l=head->r;  
    head->r=p;  
    swap(head->r);  
    swap(head->l);  
    return NULL;  
}  
  
int main()  
{  
    int lt,length;  
    BT* head=NULL;  
  
    memset(t,'\0',sizeof(t));  
    scanf("%s",&t);  
    head=creatnode(t[0]);  
    lt=strlen(t);  
    length=(double)lt;  
    level=ceil(log(length)/log(2));  
    //printf("%d\n",level);  
    creatBiTree(head,1);   //creat the tree   
  
    printf("BiTree\n");  
    printtree(head,0);  
  
    printf("pre_sequence  : ");  
    printperorder(head);  
    printf("\n");  
    printf("in_sequence   : ");  
    printinorder(head);  
    printf("\n");  
    printf("post_sequence : ");  
    printpostorder(head);  
    printf("\n");  
  
    leafnum=0;  
    countleaf(head);  
    printf("Number of leaf: %d\n",leafnum);  
    BT* heads=NULL;  
    heads=swap(head);  
    heads=head;  
    printf("BiTree swapped\n");  
    printtree(heads,0);  
    printf("pre_sequence  : ");  
    printperorder(heads );  
    printf("\n");  
    printf("in_sequence   : ");  
    printinorder(heads);  
    printf("\n");  
    printf("post_sequence : ");  
    printpostorder(heads);  
    printf("\n");  
    return 0;  
}  