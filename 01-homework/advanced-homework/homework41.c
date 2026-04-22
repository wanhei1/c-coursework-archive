#include <stdio.h>
int main( ) {
	char t,s[30];
	int i,j,n=0;
    scanf("%s",s);
    while(s[n]!='\0')
      n++;
    for(i=0;i<n-1;i++){
    	for(j=i+1;j<n;j++){
    		if(s[i]<s[j]){
    			t=s[i];
    			s[i]=s[j];
    			s[j]=t;
    		}
    	}
    }
     printf("%s\n",s); 
	return 0;
}