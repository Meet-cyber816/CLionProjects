#include <iostream>
using namespace std;

class A {
    int a;
public:
    void fun(int x) {
        a=x;
    }
};
class B{
    A obj;
public:
    void fun1(int a) {
        obj.fun(a);
    }
};

int main() {
    B obj1;
    obj1.fun1(5);
    return 0;
}