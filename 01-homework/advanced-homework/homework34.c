#include<stdio.h> 
int main() 
{ 
   int n,one,five,ten; 
   int count=0; 
   scanf("%d",&n); 
     
   for(one=1;one<100;one++) 
    { 
      for(five=1;five<100;five++) 
      { 
          for(ten=1;ten<100;ten++) 
            { 
              if(one*1+five*5+ten*10==n*100 && 1.8*one==1.5*five && 1.5*five==2.0*ten) 
               { 
                  printf("%d,%d,%d\n",one,five,ten); 
                 count++; 
               } 
            } 
      } 
    } 
  if(count==0) 
   { 
      printf("No change.\n"); 
    } 
}