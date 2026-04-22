#include<iostream>
#include<string>
using namespace std;
bool dic[50]={false},Min[50]={false},Max[50]={false};
int main(){
    string a,b,c="";
    cin>>a>>b;
   for(int i=0;i<a.size();i++){
       if(a[i]>='a'&&a[i]<='z'){
            dic[int(a[i]-'a')]=true;
       }
   } 
   for(int i=0;i<b.size();i++){
       if(b[i]=='<'){
           dic[int(b[i+1]-'a')]=false;
           dic[int(b[i+2]-'a')]=false;
            if(Max[int(b[i+1]-'a')]==false) Min[int(b[i+1]-'a')]=true;
            if(Max[int(b[i+1]-'a')]==true) Max[int(b[i+1]-'a')]=false;
            if(Min[int(b[i+3]-'a')]==false) Max[int(b[i+3]-'a')]=true;
            if(Min[int(b[i+3]-'a')]==true) Min[int(b[i+3]-'a')]=false;
       }
   }
   for(int i=0;i<26;i++){
       if(Min[i]==true || (Max[i]==false&&dic[i]==true)) c=c+char(i+'a')+',';
   }
   c.pop_back();
   cout<<c<<endl;
   c="";
   for(int i=0;i<26;i++){
       if(Max[i]==true || (Min[i]==false&&dic[i]==true)) c=c+char(i+'a')+',';
   }
   c.pop_back();
   cout<<c<<endl;
}