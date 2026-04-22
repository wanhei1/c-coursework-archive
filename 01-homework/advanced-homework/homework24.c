#include<stdio.h>

main()

{

 int n=0,i=0,j=0;char c='\0';

 scanf("%c%d",&c,&n);

 for(i=1;i<n+1;i++)

 {

  for(j=0;j<n-i;j++) printf(" ");

  printf("%c",c+i-1);

  for(j=1;i-1>0>0&&j<=2*i-3;j++) printf(" ");

  if(i-1>0) printf("%c",c+i-1);

  printf("\n");

 }

 for(i=n-1;i>0;i--)

 {

  for(j=0;j<n-i;j++) printf(" ");

  printf("%c",c+i-1);

  for(j=1;i-1>0>0&&j<=2*i-3;j++) printf(" ");

  if(i-1>0) printf("%c",c+i-1);

  printf("\n");

 }
return 0;
}