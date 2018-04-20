#include <iostream>

using namespace std;

typedef int T;

struct node{
	T info;
	node *next;
	node *back;
	node(T data = 0,node *n = NULL,node * b =NULL){
		info = data;
		next = n;
		back = b;
	}
};

class DoublyLinkedList{
private:
	node *first,*last;
	int length;
public:
	DoublyLinkedList(){
		first = last = NULL;
		length = 0;
	}
	void insert(T val){
		node *NewNode = new node(val);
		if(first == NULL)
			last = first = NewNode;
		else{
			NewNode -> back = last;
			last -> next = NewNode;
			last = NewNode; 
		}
		++length;
	}
	void insertFirst(T val){
		node *NewNode = new node(val);
		if(first == NULL)
			last = first = NewNode;
		else{
			first -> back = NewNode;
			NewNode -> next = first;
			first = NewNode;
		}
		++length;
	}

	void insertAt(T val,int pos){
		if(pos >= length || pos < 0){
			cout <<"index "<<pos<<" is Out of Range \n";
			return;
		}
		node *cur = first,* Newnode;

		if(first == NULL)
			insert(val);
		else {
			int i=0;
			while(cur -> next != NULL && i < pos){
				++i;
				cur = cur ->next;
			}
			if(pos > i + 1)
				return;
			else if(cur -> next == NULL && pos == i + 1)
				insert(val);
			else if(pos == 0)
				insertFirst(val);
			else {
				Newnode = new node(val);

				node *tail = cur -> back;
				tail -> next = Newnode;
				Newnode -> back = tail;
				Newnode -> next = cur;
			}
		}
		++length;
	}
	void pop(){//O(1)
		if(first == NULL)
			return;
		else if(first -> next == NULL){
			delete first;
			first = last = NULL;
		}else{
			last = last -> back;
			delete last -> next;
			last -> next = NULL;
		}
		--length;
	}
	void print(){
		node *cur = first ;
		while(cur != NULL){
			cout <<cur -> info <<" ";
			cur = cur -> next;
		}
		cout <<'\n';
	}
	void ClearList(){
		node *Newnode = first;
		while(first != NULL){
			Newnode = first;
			first = first->next;
			delete Newnode;
		}
		length = 0;
	}
	~DoublyLinkedList(){
		ClearList();
	}
};
int main(){
	DoublyLinkedList l;
	l.insert(2);
	l.insertFirst(8);
	l.insertAt(5,0);
	l.insertAt(10,3);
	
	l.pop();

	l.print();
	return 0;
}