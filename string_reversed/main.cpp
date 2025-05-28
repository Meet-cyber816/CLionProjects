#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1;
    cin>>s1;
    int a = s1.length();
    string s1_rev;
    char &c = s1[s1.length()];
    // while ( a != 0) {
    //     c = s1.at(--a);
    //     s1_rev = s1_rev + c;
    // }

    for (auto &c1 : s1 ) {
        s1_rev = s1_rev + c1;
        cout<<c1<<endl;
        c1--;
    }

    cout<<s1_rev;
    return 0;
}