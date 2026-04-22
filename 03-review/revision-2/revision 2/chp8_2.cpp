#include<iostream>  
#include<algorithm>  
#include<string>  
using namespace std;  
  
int sz[100],median[100],mnum;  
  
  
int Median3(int lt, int rt)   
{  
    int Middle = (lt + rt) / 2;  
    if (sz[lt] > sz[Middle])  
        swap(sz[lt], sz[Middle]);  
    if (sz[lt] > sz[rt])  
        swap(sz[lt], sz[rt]);  
    if (sz[Middle] > sz[rt])  
        swap(sz[Middle], sz[rt]);  
    swap(sz[Middle], sz[rt - 1]);  
    median[mnum] = sz[rt - 1];  
    ++mnum;  
    return sz[rt - 1];  
}  
  
void InsertSort(int lt, int rt)  
{  
    for (int i = lt + 1; i <= rt; i++)  
    {  
        int temp = sz[i];  
        if (sz[i] < sz[i-1])  
        {  
            int j = lt;    
            for (; sz[j] < temp; j++);
            for (int k = i; k > j ; k--)  sz[k] = sz[k-1];
            sz[j] = temp;                     
        }  
    }  
    return;  
}  
  
  
void QuickSort(int lt, int rt)  
{  
    if(rt-lt<5)  
    {  
        InsertSort(lt, rt);  
        return;  
    }   
    else if (lt < rt)  
    {  
        int pivot = Median3(lt, rt);  
        int  L = lt,R = rt - 1;
        while (L < R)  
        {  
            while (L < R&&sz[++L] < pivot);  
            while (L < R&&sz[--R] > pivot);  
            swap(sz[L], sz[R]);  
        }  
        swap(sz[L], sz[rt - 1]);  
          
        int Middle = L;  
        if (Middle != -1)  
        {  
            QuickSort(lt, Middle - 1);  
            QuickSort(Middle + 1, rt);  
        }  
    }  
}  
  
  
int main()  
{  
    string s1;  
    int length;  
    while(1)  
    {  
        cin>>s1;  
        if(s1[0]=='#')  break;  
        sz[length]=atoi(s1.c_str());  
        ++length;  
    }  
    QuickSort(0,length-1);  
    cout<<"After Sorting:"<<endl;  
    for(int i=0; i<length ; ++i)  
    {  
          
        cout<<sz[i]<<" ";  
    }  
    cout<<endl;  
    cout<<"Median3 Value:"<<endl;  
    if(length>5)  
    {  
        for(int i ;i<mnum;++i) cout<<median[i]<<" ";  
    }  
    else cout<<"none";  
    cout<<endl;  
}  