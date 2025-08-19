#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> myVec;
    vector<int> bi;
    vector<char> cbi;
    void Sol(int n) {
        int x;
        for (int i=0;i<n;i++) {
            cin>>x;
            if ( x<10 && x>-1)
                myVec.push_back(x);
            else
                i--;
        }
        char c;
        for (int i=0;i<n;i++) {
            cin>>x;bi.push_back(x);
            for ( int j=0;j<x;j++) {
                cin>>c;
                if ( c == 'U' || c == 'D') {
                    cbi.push_back(c);
                }
            }
        }
    }
    void Output(int n) {
        for (int i=0;i<myVec.size();i++) {
            for (int j = 0;j<bi[i];j++) {
                if ( cbi[j] == 'U') {
                        myVec[i] = dec(i);
                }
                else {
                  myVec[i] = inc(i);
                }
            }
        }
    }
    int dec(int z) {
        int x = myVec[z];
        x++;
        if ( myVec[z] == 0)
            return 9;
        return x;
    }
    int inc(int z) {
        int x = myVec[z];
        x--;
        if ( myVec[z] == 9)
            return 0;
        return x;
    }
    void displayOp() {
        for (int i : myVec) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    void displayOp1() {
        for (auto i : bi) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    void displayOp2() {
        for (auto i : cbi) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
};

int main() {
    int n;
    cin>>n;
    Solution x;
    x.Sol(n);
    x.Output(n);
    x.displayOp();
    // x.displayOp1();
    // x.displayOp2();
}