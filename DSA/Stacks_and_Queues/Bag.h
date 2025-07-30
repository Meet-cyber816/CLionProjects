#ifndef BAG_H
#define BAG_H

template <typename _T>
class Bag {
public:
    Bag(int MaxSize);
    ~Bag();

    void Add(_T);
    _T * Delete(_T&);
    void Display();

    bool IsFull();
    bool IsEmpty();
private:
    void Full();
    void Empty();

    _T *_arr;
    int MaxSize;
    int top;
};
template <typename _T>
Bag<_T>::Bag(int MaxBagSize): MaxSize(MaxBagSize) {
    _arr = new _T[MaxSize]; top=-1;
}
template <typename _T>
Bag<_T>::~Bag() {
    delete[] _arr;
}
template <typename _T>
inline bool Bag<_T>::IsFull() {
    if (top == MaxSize-1) return true; else return false;
}
template <typename _T>
inline bool Bag<_T>::IsEmpty() {
    if (top == -1) return true; else return false;
}
template <typename _T>
inline void Bag<_T>::Full() {
    std::cerr<<"Bag is full"<<std::endl;
}
template <typename _T>
inline void Bag<_T>::Empty() {
    std::cerr<<"Bag is empty"<<std::endl;
}
template <typename _T>
void Bag<_T>::Display() {
    for (int i = 0; i <= top; i++)
        std::cout << _arr[i] << " ";
    std::cout << std::endl;
}

template <typename _T>
void Bag<_T>::Add(_T x) {
    if (IsFull()) Full(); else _arr[++top] = x;
}
template <typename _T>
_T * Bag<_T>::Delete(_T &x) {
    if (IsEmpty()) {Empty();return 0;}
    int _dp = top/2; x = _arr[_dp];
    for (int ind = _dp; ind < top; ind++)
        _arr[ind] = _arr[ind + 1];
    top--; return &x;
}

#endif //BAG_H
