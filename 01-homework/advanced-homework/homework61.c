#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct node
{
    
    int data;
    struct node *next;//指针指向相同类型
};
int main()
{
    

    int n,k;
    struct node *p,*head,*tail;//建立所需指针
    scanf("%d",&n);
    int i;
    head=(struct node*)malloc(sizeof(struct node));//建立的指针都需要为它申请空间
    head->next=NULL;
    tail=head;//建立前对头指针等做好初始工作
    for(i=0; i<n; i++)
    {
    //malloc需要stdlib这个头文件
    //强制类型转换前面的括号内类型要与自身类型一致
        p=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&k);
        p->data=k;
        p->next=NULL;//如果漏了NULL这一步，在遍历的时候会无法正常运行
        tail->next=p;//tail存的是head的地址，这相当于将head接上了p
        tail=p;
    }
    p=head->next;//这里可不是直接等于head
    while(p)
    {
    
        if(p->next)
            printf("%d ",p->data);
        else
            printf("%d\n",p->data);
        p=p->next;
    }
    return 0;
}
