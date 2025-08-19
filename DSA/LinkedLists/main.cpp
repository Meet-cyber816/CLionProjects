#include <iostream>
using namespace std;


class List;
class Node {
public:
    int data;
    Node *link;
    Node(int d) {
        data = d;
        link = nullptr;
    }
};

 class List {
     Node *first;
     int size;
 public:
     List():size(0) {
         first = nullptr;
     }
     void Insert(int x, int index = -1) {
         ++size;
         if(index == -1) index = size;
         if (first == nullptr) {
             first = new Node(x);
         }
         else {
             Node *temp = first;
             Node *nn = new Node(x);
             for (int i=0; i<index-1 && temp->link != nullptr; i++) {
                 temp = temp->link;
             }
             if (index == size) {
                 temp->link = nn;
             }
             else if (index == 0) {
                 nn->link = first;
                 first = nn;
             }
             else {
                 nn->link = temp->link;
                 temp->link = nn;
             }
         }
     }
     void display() {
         int i=0;
         if (first == nullptr) {
             cout<<"Empty\n";
         }
         Node *temp = first;
         while (i<size) {
             cout<<temp->data<<" ";
             temp = temp->link;
             i++;
         }
         cout<<endl;
     }
     void Delete(int index = -1) {
         if(index == -1) index =size;
         Node *temp = first;
         for (int i=0; i<index-1 && temp->link != nullptr; i++) {
             temp = temp->link;
         }
         if (index == 0) {
             first = first->link;
             temp->link = nullptr;
             delete temp;
             size --;
         }
         else if (index == size) {
        //     cout<<"\nHello "<<temp->data<<endl;
              temp->link = nullptr;
          }
         else {
             Node *tmp = first;
             int i=0;
             while (i < size -1) {
                 tmp = tmp->link;
                 i++;
             }
             Node *tmp1 = tmp->link;
             delete tmp1;
             size--;
         }

     }

 };

int main() {
    List l;
    l.Insert(2);
    l.Insert(3);l.Insert(4);l.Insert(99);
    // cout<<endl<<count<<" Hell0"<<endl;
    l.display();
    l.Delete();
    l.display();
    l.Delete();
    l.display();
}
