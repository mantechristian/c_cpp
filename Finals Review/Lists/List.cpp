#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
//standard template library
using namespace std;
template <class T>
class node{
public:
    T item;
    node<T> *next;
    node(){
    	item = 0;
    	next = NULL;
    }
    node(T x){
    	item = x;
    	next = NULL;
    }
};
template <class T>
class List{
protected:
    node<T> *head, *tail;
    int size;
public:
	List();
	~List();
	void display();
	void append(T);
	void insertFront(T);
	bool insert(T,int);
	bool deleteItem(int);
	T getItem(int);

};

List<T>::List(){
    head = tail = NULL;
    size = 0;
}
List::~List(){
	while(size!=0)
		deleteItem(1);
}
void List::display(){
    node<T> *tmp = head;
    while(tmp!=NULL){
        printf("%d ", tmp->item);
        tmp = tmp->next;
    }
    printf("\n");
}

void List::append(int x){
    node<T> *n;
    n = new node(x);

    if(size==0)
        head = tail = n;
    else{
        tail->next = n;
        tail = n;
    }
    size++;
}

bool List::deleteItem(int p){
    node<t> *tmp, *del;
    int ctr=1;
    if(p<1 || p>size)
        return false;
    tmp = head;
    if(p==1){
        del = tmp;
        head = tmp->next;
    }
    else{
        while(ctr < p - 1){
            tmp = tmp->next;
            ctr++;
        }
        del = tmp->next;
        tmp->next = del->next;
        del->next = NULL;

        if(del == tail)
            tail = tmp;
    }
    delete(del);
    size--;
    return true;
}

T List::getItem(int p){
	if(p < 1)
		throw 1;
	else
	if(p > size)
		throw 2;
	else{
		node<t> *tmp = head;
		int c = 1;
		while(c < p){
		    tmp = tmp->next;
		    c++;
		}
		return tmp->item;
	}
}
class Stack : private List{
public:
	void push(int n) { append(n);}
	bool pop() {return deleteItem(size);}
s	void printItems(){display();}
	int peek() {return getItem(size);}
};
/*template <class T>
class newNode{
public:
	T item;
	newNode<T> *next, *prev;
	newNode(){item = 0; next = prev = NULL;}
	newNode(T x){item = x; next = prev = NULL;}
};*/

int sampleThrow(int x, int y){
	if(y == 0)
		throw "Division by Zero!";
	else
		return x%y;
}

template <class T>
class node{
public:
	T item;
	node<T> *next;
	node(){item = 0; next = NULL;}
	node(T x){item = x; next = NULL;}
};

template <class T>
class List{
private:
	node<T> *head, *tail;
	int size;
public:
	List();
	void append(T);
	T getItem(int);
};

template <class T>
List<T>::List(){
	head = tail = NULL;
	size = 0;
}

template <class T>
void List<T>::append(T x){
	node<T> *n = new node<T>(x);
	if(head==NULL)
		head = tail = n;
	else{
		tail->next = n;
		tail = n;
	}
	size++;
}

template <class T>
T List<T>::getItem(int p){
	if(p < 1 || p>size)
		throw "Invalid input!";
	else{
		node<T> *tmp = head;
		int c=1;
		while(c<p){
			tmp = tmp->next;
			c++;
		}
		return tmp->item;
	}
}

int main(){
	List<string> l;
	for(int i=1; i<7; i++)
		l.append("puyde?");
	try{
		cout<<l.getItem(3)<<endl;
	}
	catch(const char*msg){
		cout<<msg<<endl;
	}

	/*try{
		int x = sampleThrow(10,0);
		cout<<x<<endl;
	}
	catch(int x){
		cout<<x<<endl;
	}

    /*List l;
    for(int i=2; i<15; i++)
    	l.append(i);
    try{
	    cout<<l.getItem(24)<<endl;
	}
	catch(int e){
		if(e == 1)
			cout<<"Less than 1 error!\n";
		else
		if(e==2)
			cout<<"Greater than size error!\n";
	}
    l.display();
    int x;
    try{
    	  x = x/0;
    	  cout<<x<<endl;
    }
    catch(...){
    	cout<<"Division by  Zero"<<endl;
    } */
    return 0;
}

