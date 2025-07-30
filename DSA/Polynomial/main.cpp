#include <iostream>
#include <vector>
using namespace std;

struct Poly {
    int exp;
    int coeff;
};

void add(const vector<Poly> &p4,const vector<Poly> &p5, vector<Poly> &p3) {
    int i=0,j=0,k=0;
    while (i<p4.size() && j<p5.size()) {
        if (p4[i].exp == p5[i].exp) {
            p3.push_back( {p4[i].exp, p4[i].coeff + p5[j].coeff} );
            //p3[k].exp = p4[i].exp;
            i++; j++;
        }
        else {
            if (p4[i].exp > p5[j].exp) {
                p3.push_back( {p4[i].exp, p4[i].coeff } );
                i++;
            }
            else {
                p3.push_back( {p5[j].exp,  p5[j].coeff} );
               // p3[k].exp = p5[j].exp;
                j++;
            }
        }
    }
    while (i < p4.size() ) {
        p3.push_back({ p4[i].exp, p4[i].coeff });
        //p3[k].exp = p4[i].exp;
        i++;
    }
    while (j < p5.size() ) {
        p3.push_back({ p5[j].exp, p5[j].coeff });
        j++;
    }
}
void display(vector<Poly> &p3) {
    for ( auto x : p3) {
        cout<<x.coeff<<" "<<x.exp<<endl;
    }
    cout<<endl<<endl;
}


int main() {
    vector<Poly> p1(3), p2(2),ans;
    p1[0].coeff = 3;
    p1[0].exp = 2;
    p1[1].coeff = 2;
    p1[1].exp = 1;
    p1[2].coeff = 3;
    p1[2].exp = 0;
    p2[0].coeff = 4;
    p2[0].exp = 4;
    p2[1].coeff = 3;
    p2[1].exp = 1;
    display(p1);
    display(p2);
    add(p1,p2,ans);
    display(ans);
}
