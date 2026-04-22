#include <stdio.h>
#include<stdlib.h>
int main(){

char *sp;
sp=(char *)malloc(sizeof(char));
scanf("%s\n",sp);
printf("Hi,there,%s!\n",sp);
return 0;
}