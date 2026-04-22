struct Node *  connect(struct Node *x, struct Node *y, struct Node *z) 
{
	int a=x->score,b=y->score,c=z->score;  
	if (a>=b&&b>=c) 
	{  
	    x->next=y;y->next=z;z->next=NULL;  
	    return x;
	}  
	else if (a>=c&&c>=b) 
	{  
	    x->next=z;z->next=y;y->next=NULL;  
	    return x;
	}  
	else if (b>=a&&a>=c)
	{  
	    y->next=x;x->next=z;z->next=NULL;  
	    return y;
	}  
	else if (b>=c&&c>=a)
	{  
	    y->next=z;z->next=x;x->next=NULL;  
	    return y;
	}  
	else if (c>=a&&a>=b) 
	{  
	    z->next=x;x->next=y;y->next=NULL;  
	    return z;
	}  
	else if (c>=b&&b>=a) 
	{  
	    z->next=y;y->next=x;x->next=NULL;  
	    return z;
	}  
}
 
#include <stdio.h>  
#include <stdlib.h>  
  
struct Node {  
    char *name;  
    int  score;  
    struct Node *next;  
};  
  
struct Node *  connect(struct Node *x, struct Node *y, struct Node *z);  
  
int main(int argc, char *argv[]) {      
     struct Node a, b, c, *p;  
       
       
     a.name = "LiPing";  
     b.name = "LiuHai";  
     c.name = "FengYun";   
     scanf("%d,%d,%d", &a.score, &b.score, &c.score);  
     p= connect(&a,&b,&c);  
     printf("%s-%d\n",p->name,p->score);  
     p=p->next;  
     printf("%s-%d\n",p->name,p->score);  
     p=p->next;  
     printf("%s-%d\n",p->name,p->score);  
     return 0;  
}  