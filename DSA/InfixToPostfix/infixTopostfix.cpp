#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

int Pre(char c) {
    if ( c == '^')
        return 3;
    if (c == '/' || c == '*')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    // cout<<"Invalid Operator\n";
    // exit (-1);
    return -1;
}
void ItoP(string &exp) {
    stack<char> sc;

    for (char s : exp) {
        if (isalpha(s))
            cout<<s;
        else if ( s == '(' )
            sc.push(s);
        else if ( s == ')') {
            while (sc.top() != '(' ) {
                cout<<sc.top();sc.pop();
            }
            sc.pop();
        }
        else {
            if ( sc.empty() )
                sc.push(s);
            else {
                while ( !sc.empty() && ( Pre(sc.top()) >= Pre(s) ) ) {
                    cout<<sc.top(); sc.pop();
                }
                sc.push(s);
            }
        }
    }
    while ( !sc.empty() ) {
        cout<<sc.top(); sc.pop();
    }
}
int main() {
    string str;
    cout<<"Enter an expression: ";cin>>str;
    ItoP(str);
}