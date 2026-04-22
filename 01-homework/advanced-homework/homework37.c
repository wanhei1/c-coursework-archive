#include<stdio.h>   
main()
{
 int n,j,k;
 char c;
 scanf("%c,%d",&c,&n);
  for (j=1;j<=n;j++)
  {
   for (k = 1; k < 2 * n - (2 * n - (j + n)); k++)
   {
	if (k==(2*n-(j+n-1)) || k==2*n-(2*n-(j+n-1)))
	printf("%c",c+j-1);
	else printf(" ");
   }
   printf("\n");
  }
  for (j=n+1;j<=2*n-1;j++)
  {
   for (k=1;k<2*n-(j-n);k++)
   {
	if (k==(j-n+1) || k==(2*n-(j-n+1)))
	printf("%c",c+2*n-j-1);
	else printf(" ");
   }
   printf("\n");
  }
}