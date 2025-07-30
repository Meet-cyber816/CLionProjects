#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;
    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class Dlist {
    Node *first;
    int size;
public:
    Dlist() : first(nullptr), size(0) {}

    void Insert(int d, int pos = -1) {
        if (pos < 0 || pos > size)
            pos = size;

        Node *nn = new Node(d);

        if (first == nullptr) {
            first = nn;
        }
        else if (pos == 0) {
            nn->next = first;
            first->prev = nn;
            first = nn;
        }
        else {
            Node *temp = first;
            for (int i = 0; i < pos - 1 && temp->next != nullptr; i++) {
                temp = temp->next;
            }

            nn->next = temp->next;
            nn->prev = temp;

            if (temp->next != nullptr)
                temp->next->prev = nn;
            temp->next = nn;
        }
        size++;
    }

    void display() {
        Node *temp = first;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Dlist l1;

    l1.Insert(4);
    l1.Insert(3);
    l1.Insert(2, 0);
    l1.Insert(5, 2);

    l1.display();
}
