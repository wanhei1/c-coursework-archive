#include<stdio.h>

int countsub( char *str, char *ss )
{
    int count = 0, i = 0; 
    
    char *p = str, *q = ss;
    while( *p != '\0')
    {   
        q = ss; 
        if(*p == *q)
        {
            while( *p++ == *q++ )
            {
                if( *q == '\0')
                {
                    q = ss;
                    count++;
                   
                }
            }
            if( i <= count)
           
            {
                i = count;
                count = 0;   
            }
        }
        else 
            p++;
    } 

    return i; 
}
int main()
{   
    char s1[1000] = {
   0}, s2[100] = {
   0};
    gets(s1); 
    gets(s2); 

    printf("%d\n", countsub( s1, s2 ));

    return 0;
}