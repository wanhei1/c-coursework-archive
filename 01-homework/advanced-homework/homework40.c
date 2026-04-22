#include<stdio.h>

#include<string.h>

void sequence(char* a){

    int len=strlen(a);

    for(int i=0;i<len-1;i++){

        for(int j=0;j<len-1-i;j++){

            if(a[j]>a[j+1]){

                char temp;

                temp=a[j];

                a[j]=a[j+1];

                a[j+1]=temp;

            }

        }

    }

}

int main() {

    char a[100];

    char b[100];

    int isprime;

    gets(a);

    gets(b);

    isprime=strcmp(a, b);

    if (isprime < 0) {

        strcat(a,b);

        sequence(a);

        puts(a);

    }

    else {

        strcat(b, a);

        sequence(b);

        puts(b);

    }

}
