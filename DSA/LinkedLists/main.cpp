#include <iostream>
using namespace std;

static int count = 0;
class List;
class Node {
public:
    int data;
    Node *link;
    Node(int d) {
        data = d;
        link = nullptr;
        count++;
    }
};

 class List {
     Node *first;
 public:
     List() {
         first = nullptr;
     }
     void Insert(int x, int index = count) {
         if (first == nullptr) {
             first = new Node(x);
         }
         else {
             Node *temp = first;
             Node *nn = new Node(x);
             for (int i=0; i<index-1 && temp->link != nullptr; i++) {
                 temp = temp->link;
             }
             if (index == count) {
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
         while (i<count) {
             cout<<temp->data<<" ";
             temp = temp->link;
             i++;
         }
     }
     void Delete(int index = count) {
         Node *temp = first;
         for (int i=0; i<index && temp->link != nullptr; i++) {
             temp = temp->link;
         }
         if (index == 0) {
             first = first->link;
             temp->link = nullptr;
             delete temp;
             count --;
         }
         else if (index == count) {
             cout<<"\nHello "<<temp->data<<endl;
              temp->link = nullptr;
          }
         else {
             Node *tmp = first;
             int i=0;
             while (i < count -1) {
                 tmp = tmp->link;
                 i++;
             }
             Node *tmp1 = tmp->link;
             tmp->link == nullptr;
             delete tmp1;
             count--;
         }

     }

 };

int main() {
    List l;
    l.Insert(2);
    l.Insert(3);l.Insert(4, 0);l.Insert(99,1);
    // cout<<endl<<count<<" Hell0"<<endl;
    l.display();
    l.Delete();
    l.display();
    l.Delete();
    l.display();
}