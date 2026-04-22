#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	char o;
	int i,n,max,min;
	char max_c='0',min_c='9';
	gets(a);
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
		if(a[i]>max_c) max_c=a[i];
		if(a[i]<min_c) min_c=a[i];
		} 
		
	    if(a[i]=='/'||a[i]=='-'||a[i]=='+'||a[i]=='*')
		o=a[i];
	}
 
   max=max_c-'0';
   min=min_c-'0';
   
   switch(o)
   {
   case '+':printf("%d+%d=%d\n",max,min,max+min); break;
   case '*':printf("%d*%d=%d\n",max,min,max*min); break;
   case '-':printf("%d-%d=%d\n",max,min,max-min); break;
   case '/':
   if(min==0){
       printf("Error!\n");
   }
   else
   {
   printf("%d/%d=%d\n",max,min,max/min);}
    break;
   case '%':
      
if(min == 0)
      
{
      
printf("Error!\n");
      
}
      
else
      
{
      
printf("%d%%%d=%d\n", max, min, max % min);
      
}
      
break;
      
}
   return 0;
   }
