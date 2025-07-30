#include <iostream>
#include <deque>
#include <vector>
#include <list>
using namespace std;

template <typename T, template <typename ...> class container = deque >
class stack {
private:
    container<T> s;
public:
    void push(T t) {
        s.push_back(t);
    }
    void top() {
        return s.back();
    }
    void pop() {
        s.pop_back();
    }
    void printd() {
       for (auto i : s) {
           cout<<' '<<i;
       }
       cout<<endl;
    }
    void update(int index, T data) {
        if (index>=0 || index < s.size()) {
            s[index] = data;
        }
    }
    T size() {
        return s.size();
    }
};

int main() {
    stack<int, vector> vi;
    int a;
    for (int i=0;i<3;i++) {
        cin>>a;
        vi.push(a);
    }
    vi.printd();
    vi.update(0,99);
    vi.push(1000);
    vi.printd();

    stack<string, vector> vs;
    vs.push("C++");
    vs.push("is");
    vs.push("cool!");
    vs.printd();

    return 0;
}

