#include <stdio.h>
void print_star(int n)
{ int i;
  for(i=0;i<n;i++)
  printf("*");
}
int main()
{ int n;
  scanf("%d",&n);
  print_star(n);
  printf("\n");
  return 0;
}