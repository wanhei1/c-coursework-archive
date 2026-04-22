void multiplication(NODE * h1, NODE * h2, NODE * h3)  
{  
    int coefp,expp;  
    NODE *p1 = h1, *p2 = h2, *p3 = h3;  
    int exist0=0;  
    while (p1->next != NULL)   
    {  
        start: if(p1->next==NULL) break;  
        p1 = p1->next;  
        if (p1->coef == 0 && exist0)continue;  
        p2 = h2;  
        p3 = h3;     
        while (p2->next != NULL)
        {  
            p2 = p2->next;  
            coefp = p1->coef * p2->coef;  
            expp = p1->exp + p2->exp; 
            if (coefp == 0 && exist0)continue;  
            NODE *per;  
            while (p3 != NULL)   
            {  
                per = p3;  
                p3 = p3->next;  
                if (p3 == NULL|| expp< p3->exp)    
                {  
                    NODE *insert = (NODE*)malloc(sizeof(NODE));  
                    if (coefp == 0 && !exist0)   
                    {  
                        insert->exp = 0;  
                        exist0=1;  
                        insert->coef = coefp;  
                        insert->next = p3;
                        per->next = insert;  
                        p3 = per;  
                          
                        goto start; 
                    }  
                    else insert->exp = expp;  
                    insert->coef = coefp;  
                    insert->next = p3; 
                    per->next = insert;  
                    p3 = per;  
                      
                    break;  
                }  
                  
                if (expp > p3->exp)continue;  
                  
                if (p3->exp == expp) {  
                      
                    p3->coef += coefp;  
                    if (p3->coef == 0 && expp != 0)
                    {  
                        per->next = p3->next;  
                        free(p3);  
                    }  
                    p3 = per;  
                    break;  
                }  
            }  
        }  
    }  
}  