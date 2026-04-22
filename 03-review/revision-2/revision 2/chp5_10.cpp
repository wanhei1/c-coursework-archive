#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#define OK 1
#define YES 1
#define NO 0
#define ERROR 0
#define MAX_SIZE 10005

using namespace std;

const int INF = 0x3f3f3f3f;
typedef char ElemType;
typedef char AtomType;
typedef int Status;
typedef long long ll;

typedef enum {ATOM, LIST} ElemTag;
typedef struct GLNode {
    ElemTag tag;
    union {
        AtomType atom;
        struct {struct GLNode *hp, *tp;}ptr;
    };
} * Glist;

typedef struct Tnode{
    ElemType data;
    int status;
    struct Tnode * firstchild, * nextsibling;
} * Tree;

string emp("()");

Status CreateGlist(Glist &L, string s);
Status sever(string &str, string &hstr);
Glist GetHead(Glist L);
Glist GetTail(Glist L);
void CreateTree(Tree &T, Glist L);
Status pre_deal(Tree T);
Status play(Tree T);
int get_height(Tree T);
Status who_play_first();
Status illegal_move();
Tree computer_do(Tree T);
Tree human_do(Tree T);

int main() {

    string s;
    cin >> s;

    int i;
    for(i = 0; s[i] != '\0'; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') printf("%c\n", s[i]);
    }

    Glist L;
    CreateGlist(L, s);

    Tree T;
    CreateTree(T, L);
    pre_deal(T);

    play(T);
    return 0;
}

Status CreateGlist(Glist &L, string s) {  
    if(s == emp) {
        L = NULL;
    }
    else {
        L = new GLNode;
        if(s.length() == 1) {    
            L ->tag = ATOM;
            L ->atom = s[0];
        }
        else {    
            L ->tag = LIST;

            string sub, hsub;
            sub = s.substr(1, s.size() - 2);
            //cout << sub;
            Glist p, q;
            p = L;
            while(!sub.empty()) {
                sever(sub, hsub);    
                //cout << sub << endl;
                //cout << hsub << endl;
                CreateGlist(p ->ptr.hp, hsub);
                q = p;
                if(!sub.empty()) {   
                    p = new GLNode;
                    p ->tag = LIST;
                    q ->ptr.tp = p;
                }
            }
            q ->ptr.tp = NULL;
        }   
    }  
    return OK;
}

Status sever(string &str, string &hstr) {  

    int i, k = 0;
    int n = str.length();

    char ch = '\0';
    for(i = 0; i < n && (ch != ',' || k != 0); i++) {
        ch = str[i];
        if(ch == '(') {
            k++;
        }
        if(ch == ')') {
            k--;
        }
    }
    if(i < n) {
        hstr = str.substr(0, i - 1);
        str = str.substr(i, n - i);
        //cout << hstr << endl;
        //cout << str << endl;
    }
    else {
        hstr = str;
        str.clear();
    }
    return OK;
}

Glist GetHead(Glist L) {
    if(L) {
        return L ->ptr.hp;
    }
    else {
        return NULL;
    }
}

Glist GetTail(Glist L) {
    if(L) {
        return L ->ptr.tp;
    }
    else {
        return NULL;
    }
}

void CreateTree(Tree &T, Glist L) {  

    if(L) {
        T = new Tnode;
        T ->data = GetHead(L) ->atom;
        T ->firstchild = NULL;
        T ->nextsibling = NULL;

        if(GetTail(L)) {

            Glist h = GetHead(GetTail(L));
            Glist t = GetTail(GetTail(L));
            CreateTree(T ->firstchild, h);
        
            Tnode * p = T ->firstchild;
            while(t) {
                h = GetHead(t);
                t = GetTail(t);
                CreateTree(p ->nextsibling, h);
                p = p ->nextsibling;
            }
        
            p ->nextsibling = NULL;
        }
    }
    else {
        T = NULL;
    }

    return;
}

Status play(Tree T) {
    while(1) {

        who_play_first();

        int player, flag = 0;
        scanf("%d", &player);
        Tree p = T;
        switch(player) {
            case 0:
                p = computer_do(T);
                flag = 0;
                break;
            case 1:
                p = human_do(T);
                flag = 1;
                break;
            default: exit(-1);
        }
        if(p ->firstchild == NULL) {
            if(flag == 0) {
                printf("Sorry,you lost.\n");
            }
            else {
                printf("Congratulate,you win.\n");
            }
            
            printf("Continue(y/n)?\n");
                
            char c;
            getchar();
            scanf("%c", &c);

            if(c == 'y') {
                continue;
            }
            else {
                return OK;
            }
        }
        if(flag == 1 && p != T) { 
            while(1) {
                
                p = computer_do(p);
                if(p ->firstchild == NULL) {
                    printf("Sorry,you lost.\n");
                    printf("Continue(y/n)?\n");
                
                    char c;
                    getchar();
                    scanf("%c", &c);

                    if(c == 'y') {
                        break;
                    }
                    else {
                        return OK;
                    }
                } 
                
                while(1) { 
                    Tree q;
                    q = human_do(p);
                    if(q != p) {
                        p = q;
                        break;
                    }
                }
                if(p ->firstchild == NULL) {
                    printf("Congratulate,you win.\n");
                    printf("Continue(y/n)?\n");
                
                    char c;
                    getchar();
                    scanf("%c", &c);

                    if(c == 'y') {
                        break;
                    }
                    else {
                        return OK;
                    }
                } 
            }
        }
        else { 
            while(1) { 

                while(1) {
                    Tree q;
                    q = human_do(p);
                    if(q != p) {
                        p = q;
                        break;
                    }
                }
                if(p ->firstchild == NULL) {
                    printf("Congratulate,you win.\n");
                    printf("Continue(y/n)?\n");
                
                    char c;
                    getchar();
                    scanf("%c", &c);

                    if(c == 'y') {
                        break;
                    }
                    else {
                        return OK;
                    }
                }

                p = computer_do(p);
                if(p ->firstchild == NULL) {
                    printf("Sorry,you lost.\n");
                    printf("Continue(y/n)?\n");
                
                    char c;
                    getchar();
                    scanf("%c", &c);

                    if(c == 'y') {
                        break;
                    }
                    else {
                        return OK;
                    }
                }
            }
        }
    }
    return OK;
}

Status pre_deal(Tree T) { 

    if(T) {
        if(T ->firstchild == NULL) {
            T ->status = 1;
        }

        pre_deal(T ->firstchild);
        pre_deal(T ->nextsibling);

        Tnode * p = T;
        if(T ->firstchild) {
            p = T ->firstchild;
            int flag = 1;
            while(p) {
                if(p ->status == 1) {
                    flag = 0;
                    break;
                }
                p = p ->nextsibling;
            }
            if(flag) {
                T ->status = 1;
            }
            else {
                T ->status = 0;
            }
        }
    }

    return OK;
}

Status who_play_first() {
    printf("Who play first(0:computer;1:player)?\n");
    return OK;
}

Status illegal_move() {
    printf("illegal move.\n");
    return OK;
}

Tree computer_do(Tree T) { 
    int victory_h = INF, false_h = 0;
    Tree p = T, q1, q2;
    if(p ->firstchild) {
        p = p ->firstchild;
        while(p) {
            int h = get_height(p);
            if(p ->status == 1) {
                if(h < victory_h) {
                    victory_h = h;
                    q1 = p;
                }
            }
            else {
                if(h > false_h) {
                    false_h = h;
                    q2 = p;
                }
            }
            p = p ->nextsibling;
        }
        if(victory_h != INF) {
            printf("computer:%c\n", q1 ->data);
            return q1;
        }
        else {
            printf("computer:%c\n", q2 ->data);
            return q2;
        }
    }
    return T;
}

Tree human_do(Tree T) { 

    printf("player:\n");

    char c;
    getchar();
    scanf("%c", &c);

    Tnode * p = T;
    if(p ->firstchild) {
        p = p ->firstchild;
        while(p) {
            if(p ->data == c) {
                break;
            }
            p = p ->nextsibling;
        }
    }
    if(p) {
        return p;
    }
    else {
        illegal_move();
        return T;
    }
}

int get_height(Tree T) { 
    
    if(T == NULL) return 0;
    else {
        int h, h2;
        h = get_height(T ->firstchild);
        if(h != 0) {
            T = T ->firstchild;
            while(T) {
                h2 = get_height(T ->nextsibling);
                if(h < h2) {
                    h = h2;
                }
                T = T ->nextsibling;
            }
        }
        return h + 1;
    }
}


