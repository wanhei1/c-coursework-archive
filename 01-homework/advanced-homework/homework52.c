#include<stdio.h>
#include<string.h>
int main(){
    struct ren {
        int qian;
        int song;
        char name[15];
    };
    int n,i,j,k,m,money,re,cha;char c[15];
    struct ren *p[11];
    struct ren a1;p[1]=&a1;a1.qian=a1.song=0;
    struct ren a2;p[2]=&a2;a2.qian=a2.song=0;
    struct ren a3;p[3]=&a3;a3.qian=a3.song=0;
    struct ren a4;p[4]=&a4;a4.qian=a4.song=0;
    struct ren a5;p[5]=&a5;a5.qian=a5.song=0;
    struct ren a6;p[6]=&a6;a6.qian=a6.song=0;
    struct ren a7;p[7]=&a7;a7.qian=a7.song=0;
    struct ren a8;p[8]=&a8;a8.qian=a8.song=0;
    struct ren a9;p[9]=&a9;a9.qian=a9.song=0;
    struct ren a10;p[10]=&a10;a10.qian=a10.song=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%s",&p[i]->name);
    }
    for(i=1;i<=n;i++){
        scanf("%s %d %d",&c,&money,&re);
        if(re == 0){continue;}
        for(j=1;j<=n;j++){
            if(strcmp(c,p[j]->name) == 0){                        
                p[j]->song = money-money%re;
                break;
            }
        }
        money /= re;
        for(k=0;k<re;k++){
            scanf("%s",&c);
            for(m=1;m<=n;m++){
                if(strcmp(c,p[m]->name) == 0){
                    p[m]->qian += money;break;
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        cha = p[i]->qian - p[i]->song;
        printf("%s %d\n",p[i]->name,cha);
    }
    return 0;
}