#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front, rear;
    int _ms;
public:
    Queue(int size = 5) : _ms(size), front(-1), rear(-1) {
        arr = new int[_ms];
    }

    ~Queue() { delete[] arr; }

    void Enqueue(int n) {
        if (isFull()) return;

        if (front == -1) front = 0;
        rear = (rear + 1) % _ms;
        arr[rear] = n;
    }

    int dequeue() {
        if (isEmpty()) return 0;

        int val = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % _ms;
        }
        return val;
    }

    bool isFull() {
        return ((rear + 1) % _ms == front);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void display() {
        if (isEmpty()) return;
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % _ms;
        }
        cout << endl;
    }
};

int main() {
    Queue list(5);
    for (int i = 1; i <= 3; i++)
        list.Enqueue(i);
    list.display();

    list.dequeue();
    list.display();
    //
    // list.dequeue();
    // list.display();
    //
    // list.dequeue();
    // list.dequeue(); // this won't crash
    //
    // list.display();
}
