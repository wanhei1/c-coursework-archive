#include<stdio.h>     
#include<stdlib.h>     
int main()     
{     
    int n,k,m;     
    scanf("%d,%d,%d",&n,&k,&m);     
    if (n<1||k<1||m<1)     
    {     
            
        return 0;     
    }    
    if (k>n)     
    {     
          
        return 0;     
    }
     else     
    {     
        struct node     
        {     
            int id;     
            struct node *next;     
        };     
        struct node *head,*p,*q,*tmp;     
        head=(struct node*)malloc(sizeof(struct node)); 
          
        head->id=-1;     
        head->next=head;
         
        for (int i=n;i>=1;i--)     
        {     
            tmp=(struct node*)malloc(sizeof(struct node));     
            tmp->next=head->next;     
            head->next=tmp;     
            tmp->id=i;     
            if (tmp->id==k)     
            {     
              p=tmp;     
            }     
        }
        
             
        while(tmp->next!=head)  
        {  
            tmp=tmp->next;  
        }
        tmp->next=head->next;
        
        int count=0;     
        for(int i=1;i<=n;i++)     
        {     
            for(int j=1;j<m;j++)     
            {     
                p=p->next;     
            }     
            count++;     
            if((count%10)==0||i==n)     
            {     
                printf("%d\n",p->id);        
            }        
            else     
            {     
                printf("%d ",p->id);     
            }     
            p->id=p->next->id;     
            q=p->next;     
            p->next=q->next;     
            free(q);         
      }     
      free(head);
      
     }     
  return 0;     
}  
