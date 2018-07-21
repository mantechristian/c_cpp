#include <iostream>
using namespace std;

class Fraction{
private:
	int n, d;
public:
	Fraction(){ n = 0; d = 1;}
	Fraction(int n, int d) { this->n = n; this->d = d; /*simplify();*/}
	~Fraction(){ display(); cout<<"Object Destroyed!"<<endl;}
	int getNumerator() { return n; }
	int getDenominator() { return d; }
	
	void display() { cout<<n<<"/"<<d<<endl; }
	Fraction times(Fraction);
private:
	void simplify();
};
int main(){
	Fraction f(3,2), g(4,7),c;
	{
	Fraction s;
	}
	Fraction *fr = new Fraction(10,17);
	
	c = f.times(g);
	c.display();
	int x;
	int *px = new int;
	
	delete px;
	delete fr;
	return 0;
}
Fraction Fraction::times(Fraction f){
	int num = n*f.getNumerator();
	int den = d*f.getDenominator();
	
	Fraction p(num, den);
	return p;	
}

void Fraction::simplify(){
	int s = n;
	if(s > d)
		s = d;
	
	for(int t = s; t>1; t--){
		if(n%t==0 && d%t==0){
			n = n/t;
			d = d/t;
			break;
		}
	}		
}
