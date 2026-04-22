#include <iostream>
#include <string.h>
using namespace std;
void fun(char *str){
    char t;
    int i,j;
    for(i=1;i<strlen(str);i++){
        t=str[i];
        for(j=i-1;j>0&&t<str[j];j--)
        str[j+1]=str[j];
        str[j+1]=t;
    }
}

int main(){
    char s[]="CFBEAD";
    fun(s);
    cout<<s<<endl;
}