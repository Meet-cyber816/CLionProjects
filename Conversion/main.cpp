// Type conversion using templates
#include <iostream>
using namespace std;

template <typename U>
class Hello {
        U a,b;
    public:
        Hello ()= default;
        template <typename M>
        Hello (M &obj) {
             a = obj.getA() ;
             b = obj.getB();
        }
        // template <typename T>
        // operator T() {
        //     return a;
        // }
        void setData(U x, U y) {
            a = x;
            b = y;
        }
        void showData() {
            cout << a << " " << b << endl;
        }
        U GetA(){return a;}
        U GetB(){return b;}
};

template <typename Z>
class Bye {
    Z a,b;
public:
    Bye ()= default;
    template <typename M>
    Bye (M &obj) {
        a = obj.GetA() ;
        b = obj.GetB();
    }
    void showData() {
        cout<<"This is bye: "<<a<<" "<<b<<endl;
    }
    void setData(Z x, Z y) {
        a=x;b=y;
    }
    Z getA(){return a;}
    Z getB(){return b;}
};

int main() {
    Hello<int> h1;
    h1.setData(102,4);
    char y;
    // y=h1;  // Class to basic
    // cout<<y<<endl;
    Bye<float> b1;
    b1.setData(97.28,6.3737);
    h1=b1;  // Class to Class
    // y=h1;  // Class to basic
    // cout<<y<<endl;
    h1.showData();
    Bye<char> b2;
    b2.setData('a','b');
    b2.showData();
    Hello<int> h2;
    h2.setData(112, 117);
    b2=h2;
    b2.showData();
    return 0;
}

