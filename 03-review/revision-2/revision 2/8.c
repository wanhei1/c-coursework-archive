#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack <char> s;

int main()
{
    //freopen("/Users/zhj/Downloads/test.txt","r",stdin);
    int N;
    cin >> N;
    while (N--)
    {
        string in;
        cin >> in;
        int t = 0;
        while (in[t] != '#')
        {
            if (t == 0 && in[t] == '-')
            {//第一个数就是负数
                cout << in[t];
            }
            else if (isalnum(in[t]))
            {//如果是数字字母的话就输出
                cout << in[t];
            }
            else if (in[t] == '(')
            {//是左括号的话就压入栈中
                s.push(in[t]);
            }
            else if (in[t] == ')')
            {//如果是右括号的话，栈元素弹出，将弹出的操作符输出直到遇到左括号为止
                while(s.top()!='(')
                {
                    cout<<s.top();
                    s.pop();
                }
                s.pop();
            }
            else if( in[t] =='-' && ( in[t - 1] == '(' || in[t - 1] == '*' || in[t - 1] == '/' || in[t - 1] == '%' || in[t - 1] == '+' || in[t - 1] == '-') )
            {//此时是负数，且之前的是这些个符号的话，证明当前是一个负数
                cout << in[t];
            }
            else
            {//其他的操作符，从栈中弹出元素直到遇到发现更低优先级的元素(或者栈为空)为止
                if(s.empty())
                {
                    s.push(in[t]);
                }
                else
                {
                    int x, y;//x=ch,y=top of the stack
                    while (1)
                    {
                        if (s.empty())
                        {
                            s.push(in[t]);
                            break;
                        }

                        char chtmp = s.top();//chtmp此时是栈顶的元素
                        switch (in[t])
                        {//给此时的符号标记一个优先级
                            case '^':{ x = 7; break;}
                                //10^2^2当然便是刚输入这个^优先级别更高，因为后面还可以继续续上^2，变成10^2^2^2
                            case '*':{ x = 4; break;}
                            case '/':{ x = 4; break;}
                            case '+':{ x = 2; break;}
                            case '-':{ x = 2; break;}
                        }
                        switch (chtmp)
                        {//给之前的符号标记一个优先级
                            case '^':{ y = 6; break;}
                            case '*':{ y = 5; break;}
                            case '/':{ y = 5; break;}
                            case '(':{ y = 1; break;}
                            case '+':{ y = 3; break;}
                                //如果之前是一个加号，此时的ch仍然是一个加号，那么理应该输出这个+号的，所以相应的之前的优先级大一点
                            case '-':{ y = 3; break;}
                        }

                        if (y > x || y == x)
                        {//如果原来栈顶的优先级大于之前的优先级，那么就输出
                            cout<<chtmp;
                            s.pop();
                            continue;
                        }
                        else
                        {//不优先说明仍然在累计，则压入栈中
                            s.push(in[t]);
                            break;
                        }
                    }
                }
            }
            t++;
        }
        while (!s.empty())
        {
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }
}
