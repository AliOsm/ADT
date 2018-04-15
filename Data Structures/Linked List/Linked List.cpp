#include <iostream>

using namespace std;
typedef int T;

struct node{
	T info;
	node *next;
	node(T data = 0,node *n = NULL){
		info = data;
		next = n;
	}
};
class LinkedList{
private:
	node *front,*last;
	int length;
public:
	LinkedList(){
		front = last = NULL;
		length = 0;
	}

	void insert(T val){
		node *Newnode = new node(val);
		if(front == NULL){
			front = last = Newnode;
		}else{
			last->next = Newnode;
			last = Newnode;
		}
		++length;
	}

	void insertFirst(T val){
		node *Newnode = new node(val,front);
		if(last == NULL)
			last = front = Newnode;
		else
			front = Newnode;
		++length;
	}

	void insertAt(T val,int pos){
		if(pos >= length || pos < 0){
			cout <<"index "<<pos<<" is Out of Range \n";
			return;
		}

		node *cur = front , *tail , *Newnode;
		
		if(front != NULL){
			int i=0;
			while(cur->next != NULL && i < pos){
				++i;
				tail = cur;
				cur = cur->next;
			}
			if(pos > i + 1)
				return;
			else if(cur->next == NULL && pos == i + 1)
				insert(val);
			else if(pos == 0)
				insertFirst(val);
			else {
				Newnode = new node(val);
				tail -> next = Newnode;
				Newnode -> next = cur;
			}
		}
		else 
			insert(val);
		++length;
	}

	void print(){
		node *cur = front;
		while(cur != NULL){
			cout << cur->info <<" ";
			cur = cur->next; 
		}
		cout << '\n';
	}

	void clearList(){
		node *tmp = front;
		while(front != NULL){
			tmp = front;
			front = front->next;
			delete tmp;
		}
		length = 0;
	}
	~LinkedList(){
		clearList();
	}
};
int main(){
	LinkedList l;
	l.insert(2);
	l.insertFirst(8);
	l.insertAt(5,0);
	l.insertAt(10,4);

	l.print();
	return 0;
}