#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    int ar[6] = {23,4,67,87,35,66};
    vector<int> vec(ar , ar + 6);

    for (auto i : vec) {
        cout<<i<<" ";
    }
    cout<<endl;
    const char *str="Hello World!";
    vector<char> vec1(str, str + strlen(str));

    for (auto c : vec1) {
        cout<<c;
    }
    cout<<endl;
    return 0;
}