#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

template <typename T>
struct Node{
	T data;
	Node *link;
	Node(T d, Node *first): data(d), link(first){}
};

template <typename T>
class cricular_list{
	Node<T> *first;
	int size;
public:
	cricular_list(): first(nullptr), size(0){}
	void Insert(T d, int index = -1){	
		if (index == -1) index = size;
		else index -= 1;
		if( index > size || index < 0) { cout<<"Incorrect index!\n"; exit (-1); }
		if( first == nullptr){
			size++;
			first = new Node(d, first);
			first->link = first; return;
		}
			
		size++;
		Node<T> *temp = first;
		Node<T> *nn = new Node(d, first);

		for( int i=0; i<index-1; i++)
			temp = temp->link;

		if ( index == size ){	
			nn->link = first;
			temp->link = nn;
			return;
		}
		if( index == 0){
			nn->link = first;
			Node<T> *tmp = first;
			while( tmp->link != first)
				tmp=tmp->link;
			tmp->link = nn;
			first = nn;
			return;
		}	
		nn->link = temp->link;
		temp->link = nn;
	}
	void Display(){
		Node<T> *temp = first;
		do{
			cout<<temp->data<<' ';
			temp = temp->link;
		}while(temp != first);
		cout<<endl;
	}
	T pop_back(){
		if (size == 1) {
			T _dt = first->data;
			delete first;
			first = nullptr;
			size = 0;
			return _dt;
		}
		Node<T> *temp = first;
		for(int i=1;i<size-1;i++)
			temp = temp->link;
		Node<T> *_dN = temp->link;
		T _data = _dN->data;
		temp->link = first;
		delete _dN;
		size--;
		return _data;
	}
	T pop_front(){
		Node<T> *_dN = first;
		T _data = first->data;
		if (size == 1) {
			delete first;
			first = nullptr;
			size = 0;
			return _data;
		}
		Node<T> *tmp = first;
		for(int i=0;i<size-1;i++)
			tmp = tmp->link;
		tmp->link = _dN->link;
		first = _dN->link;
		delete _dN;
		--size;
		return _data;
	}
	int Size(){ return size; }
};

int main(){
	cricular_list<float> fl;
	for(int i = 0; i < 5; i++)
		fl.Insert(i*1.1);
	fl.Display();
	fl.Insert(99.98, 1);
	fl.pop_back();
	fl.Display();
	fl.pop_front();
	fl.Display();
	cout<<"Size of fl: "<<fl.Size()<<endl;

	cricular_list<char> cl;
	for(int i=0;i<5;i++)
		cl.Insert(i + 'A');
	cl.Display();
	cl.pop_back();
	cl.Display();

	cricular_list<string> sl;
	for(int i=0; i<3;i++)
		sl.Insert("XYZ" + i);
	sl.Insert("Meet");
	sl.Display();
	sl.pop_front();
	sl.Display();
}
