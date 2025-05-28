#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
void show(vector<T> &v) {
    for (const auto d : v) {
        cout<<" "<<d;
    }
    cout<<endl;
}
int main() {
    vector<double> vd(10);
    vd.push_back(6.2);
    vd.push_back(3.7);
    vd.push_back(vd[0] + vd[1]);

    // for (const auto d : vd) {
    //     cout<<" "<<d;
    // }

    show(vd);  // Make a generalise function

    vector<string> sv;
    sv.push_back("C++");
    sv.push_back("is");
    sv.push_back("fun");
    show(sv);

    return 0;
}