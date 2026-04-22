#include<stdio.h>  
  
main()  
{  
    int d,m,y,DOW;  
    scanf("%d %d %d",&y,&m,&d);  
      
    if(d>0&&d<=31&&m>0&&m<13)  
    {  
    DOW= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;  
      
    DOW+=1;  
      
    if(DOW==7)  
    DOW=0;  
      
    printf("%d\n",DOW);  
    }  
      
    else if(!(d>0&&d<=31))  
    printf("day is error.");  
      
    else   
    printf("month is error.");  
  
}