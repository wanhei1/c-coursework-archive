#include<cstdio>
#include<cstdlib>
#include<iostream>   
#include<queue> 
#include<cstring>
using namespace std;  
typedef struct BiNode 
{ 
    char data;  
 	struct BiNode * lch;  
 	struct BiNode * rch; 
}BiNode, *BiTree; 
 
void BuildTree(BiTree &t,string Inorder,string Postorder) 
{ 
  	if (Inorder.length()==0) return; 

  	int length_Post = Postorder.length(); 
  	char Rootnode = Postorder[length_Post- 1]; 
 	int index = Inorder.find(Rootnode); 
    string lch_inorder = Inorder.substr(0, index);
    string rch_inorder = Inorder.substr(index + 1);
   	int lch_length = lch_inorder.length();
    int rch_length = rch_inorder.length();
    string rch_postorder = Postorder.substr(lch_length, length_Post - 1 - lch_length);//右孩子的后序序列 
  	string lch_postorder = Postorder.substr(0,lch_length); 
 
    t = (BiTree)malloc(sizeof(BiNode)); 
   	if (t) 
 	{ 
      	t->data = Rootnode; t->lch = t->rch = NULL; 
     	BuildTree(t->lch,lch_inorder,lch_postorder); 
        BuildTree(t->rch, rch_inorder, rch_postorder); 
  	} 
} 
 
char post[50]; 
char mid[50]; 

int Position(char c) 
{ 
	return strchr(mid, c) - mid; 
} 

void PostMidCreateTree(BiTree &pn, int i, int j, int len) 
{ 
     if (len <= 0) return; 
 
  	 pn = new BiNode; pn->lch = pn->rch = NULL; 
     pn->data = post[i]; 
     int m = Position(post[i]); 
     PostMidCreateTree(pn->lch, i - 1 - (len - 1 - (m - j)), j, m - j);
     PostMidCreateTree(pn->rch, i - 1, m + 1, len - 1 - (m - j)); 
 } 
 
void InOrderTraverse(BiTree & t) 
{ 
	if (t != NULL) 
	{ 
 		InOrderTraverse(t->lch); 
     	cout << t->data; 
      	InOrderTraverse(t->rch); 
 	} 
} 
 
void leveltravers(BiTree t) 
{ 
 	queue<BiTree> Q; 
 	BiTree cur = t; 
    Q.push(cur); 
   	while (!Q.empty()) 
 	{ 
      	cur = Q.front(); 
       	Q.pop(); 
       	printf("%c", cur->data); 
 
       	if (cur->lch) 
        { 
          	Q.push(cur->lch); 
        } 
      	
      	if (cur->rch) 
        	Q.push(cur->rch); 
    } 
} 

int main() 
{ 
    BiTree t; 
  	string Inorder; 
    string Postorder; 
  	getline(cin, Inorder); 
 	getline(cin, Postorder); 
   	BuildTree(t, Inorder, Postorder); 
  	leveltravers(t); 
   	printf("\n"); 
  	return 0; 
}
