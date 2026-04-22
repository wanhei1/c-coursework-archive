#include <iostream>
#include <string>

using namespace std;

string Str;
int Point_1 = 0, Point_2;

void GetHead()
{
    cout << "destroy tail" << endl << "free list node" << endl << "generic list: ";
    int depth = -1;
    for (int i = Point_1; Str[i] != '\0'; i++)
    {
        if (Str[i] == '(')
        {
            depth++;
            if (depth == 0)
                Point_1 = i + 1;
            continue;
        }
        if (Str[i] == ')')
        {
            depth--;
            if (depth == 0)
            {
                Point_2 = i;
                break;
            }
            continue;
        }
        if (Str[i] == ',' && depth == 0)
        {
            Point_2 = i - 1;
            break;
        }
    }
    for (int i = Point_1; i <= Point_2; i++)
        cout << Str[i];
    cout << endl;
}

void GetTail()
{
    cout << "free head node" << endl << "free list node" << endl << "generic list: ";

    int depth = -1;
    int Flag = 0;
    for (int i = Point_1; Str[i] != '\0'; i++)
    {
        if (i == Point_2)
        {
            Flag = 1;
            break;
        }
        if (Str[i] == '(')
            depth++;
        if (Str[i] == ')')
            depth--;
        if (Str[i] == ',' && depth == 0)
        {
            Str[i] = '(';
            Point_1 = i;
            break;
        }
    }
    if (Flag == 1)
    {
        cout << "()" << endl;
        return;
    }
    for (int i = Point_1; i <= Point_2; i++)
        cout << Str[i];
    cout << endl;
}

int main()
{

    cin >> Str;
    cout << "generic list: " << Str << endl;
    Point_2 = Str.length() - 1;

    int op;
    while (cin >> op)
    {
        if (op == 1)
            GetHead();
        else
            GetTail();
    }
    return 0;
}
