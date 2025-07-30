#include <iostream>
#include </home/meetpanchal/CLionProjects/DSA/Stacks_and_Queues/Bag.h>
using namespace std;

int main(){
    Bag<int> b1(4);
    b1.Add(4); b1.Add(2); b1.Add(43); b1.Add(57);
    b1.Display();
    int x;
    b1.Delete(x);
    b1.Display();
}
