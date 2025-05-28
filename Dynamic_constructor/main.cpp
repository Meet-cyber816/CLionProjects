#include <iostream>
#include <string>
using namespace std;

template <typename T>
class YeClassHai {
    T *p;
public:
    YeClassHai() {
        p = new T;
    }
    explicit YeClassHai(T val) {
        p = new T;
        *p = (val);
    }
    void setData(T data) {
        *p = data;
    }
    void showData() {
        cout<<"Ye 'p' ka data hai: "<<(*p)<<endl;
    }
};

int main() {
    YeClassHai<int> obj(5);
    obj.showData();
    YeClassHai<string> obj1("Cricket");
    obj1.showData();
    YeClassHai<double> obj2;
    obj2.setData(3.1421);
    obj2.showData();
    return 0;
}