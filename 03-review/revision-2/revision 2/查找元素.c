NODE* findelement(NODE *head) 
{  
    NODE * p = head;  
    if (p -> next == NULL || p -> next -> next == NULL) return NULL;  
    while (p -> next -> next != NULL) p = p -> next;  
    return p;  
}
