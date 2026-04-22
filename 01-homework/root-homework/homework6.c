#include <stdio.h>
#include <math.h>
int main()
{

double a,b,c,discriminant,x,x1,x2,r,i;
scanf("%lf%lf%lf",&a,&b,&c);
discriminant=b*b-4*a*c;
if(b==0&&c==0&&a==0)
{
    printf("Input error!\n");
}
else if(a==0&&b==0)
{
    printf("Input error!\n");
}
else if(a==0&&c==0)
{
    x=0;
printf("x=%.6lf\n",x);
}
else if(a==0)
{
    x=-c/b;
printf("x=%.6lf\n",x);
}
else if(b==0&&c==0)
{
    x1=0;

x2=0;
printf("x1=x2=%.6lf\n",x);
}
else if(discriminant>0)
{
    x1=(-b+sqrt(b*b-4*a*c))/(2*a);
x2=(-b-sqrt(b*b-4*a*c))/(2*a);
printf("x1=%.6lf\n",x1);
printf("x2=%.6lf\n",x2);
}
else if(discriminant==0)
{
    x1=x2=-b/(2*a);
printf("x1=x2=%.6lf\n",x1);
}
else if(discriminant<0&&b==0)
{
i=sqrt(-b*b+4*a*c)/(2*a);
printf("x1=%.6lfi\n",i);
printf("x2=-%.6fi\n",i);
}
elseif(discriminant<0){
    r=-b/(2*a);
i=sqrt(-b*b+4*a*c)/(2*a);
printf("x1=%.6lf+%.6lfi\n",r,i);
printf("x2=%.6f-%.6fi\n",r,i);
}
return0;
}