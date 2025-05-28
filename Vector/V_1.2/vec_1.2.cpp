#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector< vector<int> > vec2D;
    vector<int> vec1;
    vector<int> vec2;

    for (int i=1 ; i < 6 ; i++) {
        vec1.push_back(i);
        vec2.push_back(100 + i);
    }

    vec2D.push_back(vec1);
    vec2D.push_back(vec2);
    cout<<"Printing contents of vec2D:\n";
    for (const auto &vec : vec2D) {
        for ( auto i : vec) {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    cout<<"Total of vec1 = "<<std::accumulate(vec1.begin(), vec1.end(), 0)<<endl;

    cout<<"Total of vec 2 = "<<std::accumulate(vec2.begin(), vec2.end(), 0)<<endl;

    return 0;
}