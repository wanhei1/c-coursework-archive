#include <stdio.h>  
#include <math.h>  
#include <string.h>  
main()  
{  
    char a[10],b[10];  
    char hua,da;  
    int m=1,n=1;  
    gets(a);  
    gets(b);  
    for(int i=0;i<=6;i+=3){  
        switch(a[i]){  
            case 'H':a[i]='4';break;  
            case 'S':a[i]='3';break;  
            case 'D':a[i]='2';break;  
            case 'C':a[i]='1';break;  
            default:goto out;  
        }  
        switch(a[i+1]){  
            case '1':a[i+1]='9'+1;  
                for(int k=i+2;k<=7;k++){  
                    a[k]=a[k+1];  
                }  
                break;  
            case 'J':a[i+1]='9'+2;break;  
            case 'Q':a[i+1]='9'+3;break;  
            case 'K':a[i+1]='9'+4;break;  
            case 'A':a[i+1]='9'+5;break;  
            default:if(a[i+1]<'2'||a[i+1]>'9'){  
                goto out;  
            }  
        }  
        switch(b[i]){  
            case 'H':b[i]='4';break;  
            case 'S':b[i]='3';break;  
            case 'D':b[i]='2';break;  
            case 'C':b[i]='1';break;  
            default:goto out;  
        }  
        switch(b[i+1]){  
            case '1':b[i+1]='9'+1;  
                for(int k=i+2;k<=7;k++){  
                    b[k]=b[k+1];  
                }  
                break;  
            case 'J':b[i+1]='9'+2;break;  
            case 'Q':b[i+1]='9'+3;break;  
            case 'K':b[i+1]='9'+4;break;  
            case 'A':b[i+1]='9'+5;break;  
            default:if(b[i+1]<'2'||b[i+1]>'9'){  
                goto out;  
            }  
        }  
    }  
    for(int i=0;i<=3;i+=3){  
        for(int k=i+3;k<=6;k+=3){  
            if(a[k]>a[i]){  
                hua=a[i];  
                a[i]=a[k];  
                a[k]=hua;  
                da=a[i+1];  
                a[i+1]=a[k+1];  
                a[k+1]=da;  
            }else if(a[k]==a[i]){  
                if(a[k+1]>a[i+1]){  
                    da=a[i+1];  
                    a[i+1]=a[k+1];  
                    a[k+1]=da;  
                }else if(a[k+1]==a[i+1]){  
                    goto out;  
                }  
            }  
            if(b[k]>b[i]){  
                hua=b[i];  
                b[i]=b[k];  
                b[k]=hua;  
                da=b[i+1];  
                b[i+1]=b[k+1];  
                b[k+1]=da;  
            }else if(b[k]==b[i]){  
                if(b[k+1]>b[i+1]){  
                    da=b[i+1];  
                    b[i+1]=b[k+1];  
                    b[k+1]=da;  
                }else if(b[k+1]==b[i+1]){  
                    goto out;  
                }  
            }  
        }  
    }  
    for(int i=0;i<=6;i+=3){  
        if(a[i]>b[i]){  
            n=2;break;  
        }else if(a[i]==b[i]){  
            if(a[i+1]>b[i+1]){  
                n=2;break;  
            }else if(a[i+1]<b[i+1]){  
                n=3;break;  
            }  
        }else{  
            n=3;break;  
        }  
    }  
    for(int i=0;i<=7;i+=3){  
        switch(a[i]){  
            case '4':a[i]='H';break;  
            case '3':a[i]='S';break;  
            case '2':a[i]='D';break;  
            case '1':a[i]='C';break;  
        }  
        switch(a[i+1]){  
            case '9'+1:a[i+1]='1';  
                for(int k=8;k>i+2;k--){  
                    a[k]=a[k-1];  
                }  
                a[i+2]='0';  
                i++;break;  
            case '9'+2:a[i+1]='J';break;  
            case '9'+3:a[i+1]='Q';break;  
            case '9'+4:a[i+1]='K';break;  
            case '9'+5:a[i+1]='A';break;  
        }  
    }  
    for(int i=0;i<=7;i+=3){  
        switch(b[i]){  
            case '4':b[i]='H';break;  
            case '3':b[i]='S';break;  
            case '2':b[i]='D';break;  
            case '1':b[i]='C';break;  
        }  
        switch(b[i+1]){  
            case '9'+1:b[i+1]='1';  
                for(int k=8;k>i+2;k--){  
                    b[k]=b[k-1];  
                }  
                b[i+2]='0';  
                i++;break;  
            case '9'+2:b[i+1]='J';break;  
            case '9'+3:b[i+1]='Q';break;  
            case '9'+4:b[i+1]='K';break;  
            case '9'+5:b[i+1]='A';break;  
        }  
    }  
    if(m){  
        switch(n){  
            case 1:printf("Winner is X!\nA: %s\nB: %s\n",a,b);break;  
            case 2:printf("Winner is A!\nA: %s\nB: %s\n",a,b);break;  
            case 3:printf("Winner is B!\nA: %s\nB: %s\n",a,b);break;  
        }  
    }else{  
        out:  
            printf("Input Error!\n");  
    }  
    return 0;  
}  