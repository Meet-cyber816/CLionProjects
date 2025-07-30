#include <iostream>
using namespace std;
#include </home/meetpanchal/CLionProjects/DSA/Stacks_and_Queues/Bag.h>
template <typename _T>
Bag<_T>::Bag(int MaxBagSize): MaxSize(MaxBagSize) {
    _arr = new _T[MaxSize]; top=-1;
}
inline bool Bag::IsFull() {
    if (top == MaxSize-1) return true; else return false;
}
inline bool Bag::IsEmpty() {
    if (top == -1) return true; else return false;
}
inline void Bag::Full() {
    cerr<<"Bag is full"<<endl;
}
inline void Bag::Empty() {
    cerr<<"Bag is empty"<<endl;
}
template <typename _T>
void Bag<_T>::Display() {
    for (int i = 0; i <= top; i++)
        std::cout << _arr[i] << " ";
    std::cout << std::endl;
}

template <typename _T>
void Bag<_T>::Add(_T x) {
    if (IsFull()) Full(); else _arr[top++] = x;
}
template <typename _T>
_T * Bag<_T>::Delete(_T &x) {
    if (IsEmpty()) {Empty();return 0;}
    int _dp = top/2; x = _arr[_dp];
    for (int ind = _dp; ind < top; ind++)
        _arr[ind] = _arr[ind + 1];
    top--; return &x;
}
