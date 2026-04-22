#include<stdio.h>
int main(){
    int h;
    char c;
    scanf("%c,%d",&c,&h);
    int i=1,num=0;
    int flag =0;
    while(num<2*h-1){
        if(i==1){
            for(int j=0;j<h-i;j++)
               printf(" ");
               printf("%c",c);
               for(int j=0;j<h-i;j++)
               printf(" ");
               printf("\n");

        }
    else{
        for(int j=0;j<h-i;j++)
        printf(" ");
        printf("%c",c);
        for(int j=0;j<2*i-3;j++)
        printf(" ");
        printf("%c",c);
        for(int j=0;j<h-i;j++)
        printf(" ");
        printf("\n");

    }
    if(i>h)
    flag=1;
    if(flag==0){
        i--;
        c--;
    }
    num++;}
}