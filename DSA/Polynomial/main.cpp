#include <iostream>
#include <vector>
using namespace std;

struct Poly {
    int exp;
    int coeff;
};

typedef vector<Poly> Parray;
void add(const Parray &p4,const Parray &p5, Parray &p3) {
    int i=0,j=0,k=0;
    while (i<p4.size() && j<p5.size()) {
        if (p4[i].exp == p5[j].exp) {
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
void display(Parray &p3) {
    for ( auto x : p3) {
        cout<<x.coeff<<"x^"<<x.exp<<" + ";
    }
    cout<<" 0 "<<" = "<<" 0 ";
    cout<<endl<<endl;
}


int main() {
    Parray p1, p2,ans;
    for (int i=0;i<=5;i++)
        p1.push_back({5-i,10-i});

    for (int j=1;j<8;j++)
        p2.push_back({17-2*j, 99-7*j});
    // p1[0].coeff = 3;
    // p1[0].exp = 2;
    // p1[1].coeff = 2;
    // p1[1].exp = 1;
    // p1[2].coeff = 3;
    // p1[2].exp = 0;
    // p2[0].coeff = 4;
    // p2[0].exp = 4;
    // p2[1].coeff = 3;
    // p2[1].exp = 1;
    display(p1);
    display(p2);
    add(p1,p2,ans);
    display(ans);
}
