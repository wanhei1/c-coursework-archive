#include <stdio.h>  
char ch[100] = {0};  
char s[100][100] = {0};  
int main () {  
    int cnt1 = 0, cnt2 = 0;  
    gets(ch);  
    for (int i = 0; i < strlen(ch); i++) 
	{  
        if (ch[i] >= 'a' && ch[i] <= 'z' || ch[i] >= 'A' && ch[i] <= 'Z' ) 
		{  
        if (cnt2 == 0) cnt1 ++;  
        s[cnt1][cnt2++] = ch[i];
		}  
        else cnt2 = 0;  
    }  
    for (int i = 1; i <= cnt1; i++) 
	{  
        for (int j = 1; j < cnt1; j++) 
		{  
            if (strcmp(s[j], s[j + 1]) > 0) 
			{  
                char t[100] = {0};  
                strcpy(t, s[j]);  
                strcpy(s[j], s[j + 1]);  
                strcpy(s[j + 1], t);  
            }  
        }  
    }  
    for (int i = 1; i <= cnt1; i++) 
	{  
        if (i != cnt1)  printf("%s ", s[i]);  
        else printf("%s\n", s[i]);
	}  
    return 0;  
}