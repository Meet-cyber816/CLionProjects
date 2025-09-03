#include <iostream>
using namespace std;

struct node{
		int data;
		node *left,*right;
public:
		node(int d):data(d), left(nullptr), right(nullptr){}
		node(){}
};

class bst{
	node *head;
public:
	node* getHead(){ return this->head; }
	bst():head(nullptr){} 
	void insert(int x, node* root = nullptr){
			if( root == nullptr ){
					root = head;
					if( root == nullptr){
							head = new node(x); return;
					}
			}		
			if ( root->data > x ){
					if(root->left == nullptr){
							root->left = new node(x);
							cout<<x<<" inserted in left of "<<root->data<<"\n";
					}
					else
						insert(x,root->left);
			}
			else{
				if(root->right == nullptr){
						root->right = new node(x);
						cout<<x<<" inserted in right of "<<root->data<<"\n";
				}
				else
						insert(x,root->right);
			}
	}
	void inorder(node *root){
			if(root == nullptr)
				return;
			inorder(root->left);
			cout<<root->data<<" ";
			inorder(root->right);
	}
	
	node* find(node *root, int y) {
    if (root == nullptr) return nullptr;
    
    if (root->data == y) 
        return root;
    else if (y < root->data) 
        return find(root->left, y);
    else 
        return find(root->right, y);
	}	

	
	node* succ(int d){
			node* m = find(head, d); 
			if (m == nullptr) return nullptr;
			if(m->right != nullptr){
					node *temp = m->right;
					while(temp->left != nullptr)
						temp = temp->left;
					return temp;
			}	
			node* succ = nullptr;
			node* root = head;
			while (root != nullptr) {
        if (d < root->data) {
            succ = root;  
            root = root->left;
        } 
        else if (d > root->data) {
            root = root->right;
        }
        else break;
    }
    return succ;
	}
};

int main(int argc, char **argv)
{
	bst b;
	b.insert(0);
	b.insert(16);
	b.insert(-3);
	b.insert(99);
	b.insert(-5);
	b.insert(-2);
	b.insert(14);
	b.insert(7);
	b.inorder(b.getHead());
	cout<<endl;
	node *d = b.succ(-2);
	cout<<"succ of -5: "<<d->data<<endl;
	return 0;
}

