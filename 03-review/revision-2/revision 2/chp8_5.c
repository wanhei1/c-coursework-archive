#include<stdio.h>
#include<string.h>
int main() {
	int a, i, ad, s, n;
	char c;
	scanf("%d", &a);
	getchar();
	for (i = 0;i < a;i++) {
		ad = s = 0;
		n = 0;
		while ((c = getchar()) != '\n') {
			if (c == '+') {
				n++;
				if (n > ad)
					ad = n;
			}
			else {
				n--;
				if (n < s)
					s = n;
			}
		}
		printf("%d\n", ad - s);
	}
}
