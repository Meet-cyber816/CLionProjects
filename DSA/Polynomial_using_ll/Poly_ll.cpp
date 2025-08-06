#include <iostream>
using namespace std;

struct ele {
    ele *next;
    int coef;
    int power;
    ele(const int c, const int p): next(nullptr), coef(c), power(p){}
};

class Poly {
    ele *first;
    int size;
public:
    Poly():first(nullptr), size(0){}
    void Insert(const int coef, const int power) {
        if (first == nullptr) {
            first = new ele(coef, power);
            size = 1; return;
        }
        ele *nn = new ele(coef, power);
        ele *tmp = first;
        while (tmp->next != nullptr)
            tmp = tmp->next;
        tmp->next = nn;
    }
    void add(const Poly &obj1, const Poly &obj2, Poly &res) {
        int i=0,j=0;
        while (i<obj1.size && j<obj2.size) {
            if (obj1[i].exp == obj2[j].exp) {
                p3.Insert(obj1.exp, obj1[i].coeff + obj2[j].coeff);
                //p3[k].exp = obj1[i].exp;
                i++; j++;
            }
            else {
                if (obj1[i].exp > obj2[j].exp) {
                    p3.push_back( {obj1[i].exp, obj1[i].coeff } );
                    i++;
                }
                else {
                    p3.push_back( {obj2[j].exp,  obj2[j].coeff} );
                    // p3[k].exp = obj2[j].exp;
                    j++;
                }
            }
        }
        while (i < obj1.size() ) {
            p3.push_back({ obj1[i].exp, obj1[i].coeff });
            //p3[k].exp = obj1[i].exp;
            i++;
        }
        while (j < obj2.size() ) {
            p3.push_back({ obj2[j].exp, obj2[j].coeff });
            j++;
        }
    }
};