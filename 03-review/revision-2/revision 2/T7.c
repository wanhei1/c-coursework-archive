#include <stdio.h>     
#include <string.h>
#define X 1005
char a[X],b[X],ans[X];
char a1[X],b1[X],a2[X],b2[X],ans1[X],ans2[X];
int c=0,d,e;
int main() {    
    
	scanf("%s",&a);
    scanf("%s",&b);
    int a_dot,b_dot;
    
{   int k;
    
	if ( strstr(a,".") ) {
    	k=0;
    	while ( a[k] != '.' ) {
    		a1[k] = a[k];
			k++;
    	}
		a1[k] = '\0';
    	a_dot = k;
    	
    	k++;
    	int i=0;
    	while ( a[k] != '\0' ) {
    		a2[i] = a[k];
			k++; i++;
		}   a2[i] = '\0';

    	k=0;
    	while ( a1[k] == '0' ) k++;
    	for (i=0;i<=a_dot-k;i++) {
    		a1[i]=a1[i+k];
		}
		if (a1[0]=='\0') {
			a1[0]='0'; a1[1]='\0';
		} 
	}
	
	else {
		int i = 0 , e1 = strlen(a);
		a_dot = 0;
		while ( a[i] == '0' ) i++;
		if ( i == e1 ) {
			a1[0]='0'; a1[1]='\0';
		} 
		else {
			int j=0;
			while ( i < e1 ) {
				a1[j] = a[i];
				i++; j++;
			}
		}
	} 
    
	if ( strstr(b,".") ) {
    	k=0;
    	while ( b[k] != '.' ) {	b1[k] = b[k]; k++; }
		b1[k] = '\0';
    	b_dot = k;
    	
    	k++;
    	int i=0;
    	while ( b[k] != '\0' ) {
    		b2[i] = b[k];
			k++; i++;
		}   b2[i] = '\0';

    	k=0;
    	while ( b1[k] == '0' ) k++;
    	for (i=0;i<=b_dot-k;i++) {
    		b1[i]=b1[i+k];
		}
		if (b1[0]=='\0') {
			b1[0]='0'; b1[1]='\0';
		} 
	}
	
	else {
		int i = 0 , e2 = strlen(b);
		b_dot = 0; 
		while ( b[i] == '0' ) i++;
	
		if ( i == e2 ) {
			b1[0]='0'; b1[1]='\0';
		} 
		else {
			int j=0;
			while ( i < e2 ) {
				b1[j] = b[i];
				i++; j++;
			}
		}
	} 

}
    


{
	c = 0;
	int e3 = a_dot > 0 ? strlen(a2) : 0 ;
	int e4 = b_dot > 0 ? strlen(b2) : 0 ;
	int e = e3 > e4 ? e3 : e4 ;
	if (e==0) { 
		d = 0;
	} 
	else {
		d = 1;
		for (int i=e-1;i>=0;i--) {
			a2[i] = ( a2[i]>='0' && a2[i]<='9' ) ? a2[i] : '0';
			b2[i] = ( b2[i]>='0' && b2[i]<='9' ) ? b2[i] : '0';
			ans2[i] = a2[i] + b2[i] - '0' + c;
			
			c = 0;
			if ( ans2[i]>'9' ) {
				ans2[i] = ans2[i] - 10;
				c = 1;
			}
		}
	}
	ans2[e] = '\0';
}

{
	
	int e5=strlen(a1) , e6=strlen(b1) ;
	e = e5 > e6 ? e5 : e6 ;
	for (int i=e;i>0;i--) {
		a1[i] = i >= e - e5 + 1 ? a1[i-(e-e5)-1] : '0' ;
		b1[i] = i >= e - e6 + 1 ? b1[i-(e-e6)-1] : '0' ;
		ans1[i] = a1[i] + b1[i] - '0' + c;
		
		c = 0;
		if ( ans1[i]>'9' ) {
			ans1[i] = ans1[i] - 10;
			c = 1;
		}
	}
	ans1[0] = c + '0';
	ans1[e+1] = '\0';
	if (ans1[0]=='0') {
		for (int i=0;i<=e;i++) {
			ans1[i] = ans1[i+1];
		}
	}
}
	
	int e7 = strlen(ans1) , e8 = strlen(ans2);
	
	int l;
	if ( a_dot * b_dot == 0 ) {
		if ( d == 0 ) l = strlen(a) > strlen(b) ? strlen(a) : strlen(b) ;
		else if ( a_dot == 0 ) l = strlen(a) > b_dot ? strlen(a) : b_dot ;
		else 				   l = a_dot > strlen(b) ? a_dot : strlen(b) ;
	}
	else l = a_dot > b_dot ? a_dot : b_dot ;
	if ( e7 > l ) l = e7 ;
	l = l + 3 ;
	int output_length = l + e8 + d ;
	
	if (a_dot>0) {
		for (int i=0;i<l-a_dot;i++) putchar(' ');
		printf("%s",a);
		for (int i=0;i<a_dot+e8+d-strlen(a);i++) putchar(' ');
	}
	else {
		for (int i=0;i<l-strlen(a);i++) putchar(' ');
		printf("%s",a);
		if (d==1) for (int i=0;i<e8+1;i++) putchar(' ');
	}
	putchar('\n');
	
	putchar('+');
	if (b_dot>0) {
		for (int i=1;i<l-b_dot;i++) putchar(' ');
		printf("%s",b);
		for (int i=0;i<b_dot+e8+d-strlen(b);i++) putchar(' ');
	}
	else {
		for (int i=1;i<l-strlen(b);i++) putchar(' ');
		printf("%s",b);
		if (d==1) for (int i=0;i<e8+1;i++) putchar(' ');
	}
	putchar('\n');
	
	
	for (int i=0;i<output_length;i++) putchar('-');
	putchar('\n');
	
	for (int i=0;i<l-e7;i++) putchar(' ');
	printf("%s",ans1);
	if ( d == 1 ) {
		printf(".%s",ans2);
	}
	putchar('\n');
	
	return 0; 
}  