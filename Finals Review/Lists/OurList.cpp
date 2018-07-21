#include <iostream>
using namespace std;

class node{
public:
	int item;
	node* next;
	node(){//default constructor
		item=0;
		next=NULL;
	}
	node(int x){//overloaded constructor
		item=x;
		next = NULL;
	}
};

class List{
private:
	node *head, *tail;
	int size;
public:
	List(){head = tail = NULL; size = 0;}
	void append(int);
	bool deleteItem(int);
	void insertFront(int);
	void display();
	~List();
};

//Queue q; q.insertFront();

class Queue:private List{
public:
	Queue();
	void enqueue(int x){ append(x); }
	bool dequeue(){ return deleteItem(1); }
};
List::~List(){
	while(head!=NULL)
		deleteItem(1);
}

void List::append(int x){
	node *n = new node(x);

	if(head==NULL)
		head = tail = n;
	else{
		tail->next = n;
		tail = n;
	}
	size++;
}

void List::insertFront(int x){
	node *n = new node(x);

	if(head==NULL)
		head = tail = n;
	else{
		n->next = head;
		head = n;
	}
	size++;
}

bool List::deleteItem(int p){
	if(p<1 || p>size)
		return false;
	else{
		node *del;
		if(p==1){
			del = head;
			head = head->next;
			del->next = NULL;
		}
		else{
			node *tmp = head;
			int ctr = 1;
			while(ctr<p-1){
				tmp = tmp->next;
				ctr++;
			}
			del = tmp->next;
			tmp->next = del->next;
			if(del==tail)
				tail = tmp;
			del->next = NULL;
		}
		delete del;
		size--;
		return true;
	}
}

void List::display(){
	node *tmp = head;
	while(tmp!=NULL){
		cout<<tmp->item<<" ";
		tmp = tmp->next;
	}
	cout<<endl;
}
