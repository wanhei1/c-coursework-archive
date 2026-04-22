#include <stdio.h>  
#include <math.h>  
#include <string.h>  
main()  
{  
    int l,y;  
    scanf("%d %d",&l,&y);  
    int a[l],b[y],c[l];  
    for(int i=0;i<l;i++){  
        c[i]=-1;  
    }  
    for(int i=0;i<l;i++){  
        scanf("%d",&a[i]);  
    }  
    for(int i=0;i<y;i++){  
        scanf("%d",&b[i]);  
    }  
    for(int i=0;i<l;i++){  
        for(int m=i+1;m<l;m++){  
            if(a[m]>a[i]){  
                int v=a[i];  
                a[i]=a[m];  
                a[m]=v;  
            }  
        }  
    }  
    for(int i=0;i<l;i++){  
        for(int m=0;m<y;m++){  
            if(b[m]>=a[i]&&c[i]==-1){  
                c[i]=b[m];  
            }else if(b[m]>=a[i]){  
                if(b[m]<c[i]){  
                    c[i]=b[m];  
                }  
            }  
        }  
        for(int m=0;m<y;m++){  
            if(b[m]==c[i]){  
                b[m]=0;  
                break;  
            }  
        }  
    }  
    int w=1,sum=0;  
    for(int i=0;i<l;i++){  
        if(c[i]==-1){  
            w=0;  
            break;  
        }else{  
            sum+=c[i];  
        }  
    }  
    if(w){  
        printf("%d\n",sum);  
    }else{  
        printf("bit is doomed!\n");  
    }  
    return 0;  
}  