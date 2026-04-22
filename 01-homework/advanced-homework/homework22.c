 #include <stdio.h>
int main(int argc, char *argv[]) {   
     
int y,m,d,k=0,i,j,l,n,r;
     
scanf("%d %d %d",&y,&m,&d);
     
int x,p;
     
scanf("%d",&x);
     
switch(m)
     
{
     
 case 1:k=d;break;
     
  case 2:k=31+d;break;
     
  case 3:k=31+28+d;break;
     
  case 4:k=31+28+31+d;break;
     
  case 5:k=31+28+31+30+d;break;
     
  case 6:k=31+28+31+30+31+d;break;
     
  case 7:k=31+28+31+30+31+30+d;break;
     
  case 8:k=31+28+31+30+31+30+31+d;break;
     
  case 9:k=31+28+31+30+31+30+31+31+d;break;
     
  case 10:k=31+28+31+30+31+30+31+31+30+d;break;
     
  case 11:k=31+28+31+30+31+30+31+31+30+31+d;break;
     
  case 12:k=31+28+31+30+31+30+31+31+30+31+30+d;break;
     
  }
     
  i=(y-1)/4;
     
  j=(y-1)/400;
     
  l=(y-1)/100;
     
  n=(y-1)%4;
     
 
     
r=(365+365+365+366)*i+n*365+k-l+j;
     
  if(y%400==0&&m>2)
     
p=r+x+1;
     
else if(y%4==0&&m>2&&y%100!=0)
     
   p=r+x+1;
     
   else
     
  p=r+x;
     
int oneb,fourb;
     
oneb=p/((365*3+366)*25);
     
fourb=p/(((365*3+366)*25)*4);
     
int p1;
     
p1=p+oneb-fourb;
     
int y1,m1,d1,y2,y3;
     
y1=p1/(366+365*3);
     
y2=(p1-y1*(366+365*3))/365;
     
y3=4*y1+y2+1;
     
d1=p1-y1*(366+365*3)-y2*365;
     
if(d1<=31)
     
m1=1;
     
else if(d1<=31+28)
     
m1=2;
     
else if(d1<=31+28+31)
     
m1=3;
     
else if(d1<=31+28+31+30)
     
m1=4;
     
else if(d1<=31+28+31+30+31)
     
m1=5;
     
else if(d1<=31+28+31+30+31+30)
     
m1=6;
     
else if(d1<=31+28+31+30+31+30+31)
     
m1=7;
     
else if(d1<=31+28+31+30+31+30+31+31)
     
m1=8;
     
else if(d1<=31+28+31+30+31+30+31+31+30)
     
m1=9;
     
else if(d1<=31+28+31+30+31+30+31+31+30+31)
     
m1=10;
     
else if(d1<=31+28+31+30+31+30+31+31+30+31+31)
     
m1=11;
     
else
     
m1=12;
     
int d2=0;
     
switch(m1)
     
  {
     
 case 1:d2=d1;break;
     
  case 2:d2=d1-31;break;
     
  case 3:d2=d1-(31+28);break;
     
  case 4:d2=d1-(31+28+31);break;
     
  case 5:d2=d1-(31+28+31+30);break;
     
  case 6:d2=d1-(31+28+31+30+31);break;
     
  case 7:d2=d1-(31+28+31+30+31+30);break;
     
  case 8:d2=d1-(31+28+31+30+31+30+31);break;
     
  case 9:d2=d1-(31+28+31+30+31+30+31+31);break;
     
  case 10:d2=d1-(31+28+31+30+31+30+31+31+30);break;
     
  case 11:d2=d1-(31+28+31+30+31+30+31+31+30+31);break;
     
  case 12:d2=d1-(31+28+31+30+31+30+31+31+30+31+30);break;
     
  }
     
  if(y3%4==0&&y3%100!=0&&m1>2)
     
{   
     
d2=d2-1;
     
}
     
if(y3%400==0&&m1>2)
     
{   
     
d2=d2-1;
     
}
     
if(m1==1&&d2==0)
     
{   
     
m1=12;
     
d2=31;
     
y3=y3-1;
     
}
     
if(y3%4==0&&y3%100!=0&&m1==3&&d2==0)
     
{   
     
m1=2;
     
d2=29;
     
}
     
if(y3%400==0&&m1==3&&d2==0)
     
{   
     
m1=2;
     
d2=29;
     
}
     
printf("%d.%d.%d\n",y3,m1,d2);
     
return 0;}
    
   