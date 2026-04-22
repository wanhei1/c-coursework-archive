#include<stdio.h>
main(){
    int i;
    float sum=0,Max,Min;
    for(i=1;i<=10;i++)
    {
        float x;
        scanf("%f",&x);
        sum+=x;
        if(i==1)
        {
            Max=Min=x;
        }
        if(i!=1&&Max<x)
        Max=x;
        if(i!=1&&Min>x)
        Min=x;

    }
    printf("Canceled Max Score:%.0f\n",Max);
    printf("Canceled Min Score:%.0f\n",Min);
    printf("Average Score:%.0f\n",sum/10);
    return 0;
}