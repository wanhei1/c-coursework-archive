#include<stdio.h>
int main()
{
    int x;
    double t,t1,t2;
    int ii=0;
    for(ii=0;ii<3;ii++)
    {
        scanf("%d",&x);
        switch(x){
            case 1 :
            scanf("%lf",&t);
            t1=(t-32)*5/9;
            printf("The Centigrade is %.2f\n",t1);
            break;
            case 2:
            scanf("%lf",&t);
            t2=(t*9/5)+32;
            printf("The Fahrenheit is %.2f\n",t2);
            break;
            case 3: printf("Wrong input!\n");
            break;
                    }
    }
}
