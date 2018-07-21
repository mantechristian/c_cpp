#include <iostream>

using namespace std;
class MyClass{
public:
	int n,m;
public:
	MyClass(){
		n = m = 0;
	}
	friend void display(MyClass);
};

void display(MyClass m){
	cout<<m.n<<" "<<m.m<<endl;
}

void reSet(MyClass &m){
	cout<<&m<<endl;
	m.n = 3;
	m.m = 102;
}
int main(){
	MyClass c;
	int x = 3, y = -7;
	int &rx = x, *px = &x;
	x = 17;
	rx = y;
	px = &y;
	*px = 99;
	cout<<x<<endl;
	cout<<&c<<endl;
	reSet(c);
	display(c);
}
