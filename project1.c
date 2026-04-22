void inverse(LinkList head){    
    LinkList p=head->next;    
    head->next=NULL;    
    while(p!=NULL){    
        LinkList q=p->next;    
        p->next=head->next;    
        head->next=p;    
        p=q;    
    }    
} 