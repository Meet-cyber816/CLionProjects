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
        size++;
    }

    int getSize(){return size;}

    ele* getFirst(){ return this->first; }

    void add( Poly &obj1,  Poly &obj2) {
        ele *tmp1 = obj1.getFirst();
        ele *tmp2 = obj2.getFirst();
        int i=0,j=0;
        while (i<obj1.getSize() && j<obj2.getSize()) {
            if (tmp1->power == tmp2->power) {
                Insert( tmp1->coef + tmp2->coef, tmp1->power);
                i++; tmp1 = tmp1->next; j++; tmp2 = tmp2->next;
            }
            else {
                if (tmp1->power > tmp2->power) {
                    Insert( tmp1->coef, tmp1->power  );
                    i++; tmp1 = tmp1->next;
                }
                else {
                    Insert( tmp2->coef,  tmp2->power );
                    j++; tmp2 = tmp2->next;
                }
            }
        }
        while (i < obj1.getSize() ) {
            Insert( tmp1->coef, tmp1->power );
            i++; tmp1 = tmp1 ->next;
        }
        while (j < obj2.getSize() ) {
            Insert( tmp2->coef, tmp2->power );
            j++; tmp2 = tmp2 ->next;
        }
    }
    void display() {
        ele *tmp = this->first;
        while ( tmp != nullptr) {
            cout<<tmp->coef<<"x^"<<tmp->power<<" + ";
            tmp = tmp -> next;
        }
        cout<<" 0 "<<" = "<<" 0 ";
        cout<<endl<<endl;
    }
};

int main() {
    Poly p1,p2,p3;

    for (int i=1;i<=5;i++)
        p1.Insert(6-i,10-i);
    for (int i=1;i<=6;i++)
        p2.Insert(7-i,10-i);
    p1.display();
    p2.display();
    p3.add(p1,p2);
    p3.display();
}