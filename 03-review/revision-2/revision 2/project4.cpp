#include<iostream>  
using namespace std;  
int main(){  
    int func[6]={1,2,3,4,5,6};  
    
    int ct[6][6]={{1,2,3,4,5,6},  
                 {2,1,4,3,6,5},  
                 {3,5,1,6,2,4},  
                 {4,6,2,5,1,3},  
                 {5,3,6,1,4,2},  
                 {6,4,5,2,3,1}};  
   
    int uni=0,flag;  
   
    for(int k=0;k<6;++k)      
    {  
        flag=1;  
       
        for(int i=0;i<6;++i)    
        {  
            for(int j=0;j<6;++j)  
            {  
                if(ct[i][j]!=func[i]) flag=0;  
            }  
        }    
        
        for(int j=0;j<6;++j)    
        {  
            for(int i=0;i<6;++i)  
            {  
                if(ct[i][j]!=func[j]) flag=0;  
            }   
        }  
     
        if(flag)   
        {  
            uni=k;  
            break;  
        }  
    }  
    char get[3];  
    scanf("%s",get);  
    int g=get[1]-'0'-1; 
    
    for(int i=0;i<6;++i)  
    {  
        if(ct[g][i]==func[uni] && ct[i][g]==func[uni])  
        {  
            printf("f%d\n",i+1);  
            break;  
        }  
          
    }  
   
    return 0;   
}  