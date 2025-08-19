#include <iostream>
using namespace std;

struct Node{
		int data;
		Node *left,*right;
		Node(int d):data(d), left(nullptr), right(nullptr){}
};

class Tree{
		Node *root;
public:
		Tree():root(nullptr){}
		void Insert(int d, Node* tmp = nullptr){
			if(root == nullptr){
					root = new Node(d);return;
			}			
			if(tmp == nullptr)
				tmp = root;
			
			char c; cout<<"Enter l/r: ";cin>>c;
			if( c == 'r'){
				if( tmp->right == nullptr){
						Node *nn = new Node(d);
						tmp->right = nn;
				}
				else
						Insert(d, tmp->right);
			}
			else{
				if( tmp->left == nullptr){
					Node *nn = new Node(d);
					tmp->left = nn;
				}
				else
					Insert(d, tmp->left);
			}
		}			
		void display() {
    if (root == nullptr) {
        cout << "Tree is empty\n";
        return;
    }
    cout << root->data;
    if (root->left) cout << "\t" << root->left->data;
		}

};	

int main(int argc, char **argv)
{
	Tree t;
	t.Insert(4);t.Insert(6); t.display();
	return 0;
}

