#include <stdio.h>
#include <string.h>
 
#define N 80
 
int in(char chs[],char ch) {
    int i = 0;
    while(chs[i]) {
        if(chs[i] == ch) return 1;
        ++i;
    }
    return 0;
}
         
int main() {
    char s[X],t[X],st[X];
    int i,j;
    scanf("%s%s",s,t);
    for(i = 0,j = 0; s[i] != '\0';i++) 
        if(!in(t,s[i])) st[j++] = s[i];
    st[j] = '\0';
    printf("%s\n",st);
}