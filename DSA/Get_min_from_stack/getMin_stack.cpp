#include <iostream>
#include <stack>
using namespace std;

/** This Function returns the minimum element
 * from the stack at any given point of time
 */
 
int get_Min(stack<int> _sti) {
    stack<int> myStack;
    myStack.push(_sti.top());
    _sti.pop();
    while (!_sti.empty()) {
        if (_sti.top() < myStack.top()) {
            myStack.pop();
            myStack.push(_sti.top());
        }
        _sti.pop();
    }
    return myStack.top();
}

int main() {
    stack<int> s1;
    // for (int i=1;i < 10;i++) {
    //     s1.push(i*2);
    // }
    s1.push(77); s1.push(1); s1.push(12); s1.push(99); s1.push(34);
    cout<<get_Min(s1)<<endl;

}
