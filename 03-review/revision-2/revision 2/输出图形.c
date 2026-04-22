#include <stdio.h>  
char add (char s, int d) 
{ 
    d %= 26; 
    s += d; 
    while (s > 'Z') s += 'a' - 'z' - 1; 
    return s ; 
} 
int main () 
{ 
    int n; 
    char s; 
    scanf("%d %c", &n, &s); 
    if (s >= 'a' && s <= 'z') s += 'A' - 'a'; 
    if (s > 'Z' || s < 'A' || n < 0 ||n % 2 == 0) 
	printf("input error!\n"); 
    else if (n == 1) printf("%c\n", s); 
    else 
	{ 
        for (int j = 1; j <= n; j++) 
		printf("%c", add(s, j - 1)); 
        printf("\n"); 
        for (int i = 1; i <= n - 2; i++) 
		{ 
            for (int j = 1; j <= n; j++) 
			{ 
                if (j != n / 2 + 1 && j != 1 && j != n) 
				printf(" "); 
                else 
				printf("%c", add(s, i + j - 1)); 
            } 
            printf("\n"); 
        } 
        for (int j = 1; j <= n; j++) 
		printf("%c", add(s, n - 2 + j)); 
        printf("\n");  
   } 
  return 0; 
}