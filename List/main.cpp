#include <iostream>
using namespace std;

template <typename T>
class List {
    T val;
    T *ptr;
    static T **_pv;
    static int count;
public:
    List() {
        count++;
        if (count<1)
            _pv = &ptr;
        if (count >1)
            *_pv = &val;
        _pv = &ptr;
    }
    explicit List(T data) {
        count ++;
        val = data;
        if (count<1)
            _pv = &ptr;
        if (count >1)
            *_pv = &val;
        _pv = &ptr;
    }
    void getData() {
        cin>>val;
    }
    void showData() {
        cout<<val<<endl;
    }
    void showPoint() {
        cout<<*ptr<<endl;
    }
};

template <typename T>
T** List<T>::_pv = nullptr;

template <typename T>
int List<T>::count = 0;

int main() {
    List<int> l1(2),l2,l3(5);
    l2.getData();
    l1.showData();
    l1.showPoint();
    l2.showPoint();
    return 0;
}