#include <iostream>
using namespace std;
class fraction{
protected:
	int n,d;
private:
	static int ctr;
public:
	int getCount(){return ctr;}
	fraction();
	fraction(int,int);
	~fraction(){ cout<<"Destroyed!"<<n<<"/"<<d<<endl;}
	int getNumerator();
	int getDenominator();
	void setNumerator(int);
	void setDenominator(int);
	void display();
	void setFraction(int a,int b){n = a; d= b;}
	fraction times(fraction);
	fraction operator*(fraction f){
		return fraction(n*f.n,d*f.d);
	}
	friend ostream& operator<<(ostream &, fraction);
};

ostream& operator<<(ostream &out, fraction f){
	cout<<f.n<<"/"<<f.d;
	return out;
}

int fraction::ctr = 0;

class MixedFraction : public fraction{
private:
	int w;
public:
	MixedFraction() {w = 0;  setFraction(0,1);}
	MixedFraction(int a) {w = a;setFraction(0,1);}
	MixedFraction(int a,int b,int c) {w=a;setFraction(b,c);}
	MixedFraction(fraction f){w=0; setFraction(f.getNumerator(),f.getDenominator());}
	MixedFraction(char *);
	MixedFraction times(MixedFraction);
	fraction toImproper();
	void display(){cout<<w<<" "<<getNumerator()<<"/"<<d<<endl;}
};

fraction MixedFraction::toImproper(){
	return fraction(d*w + n, d);
}

MixedFraction MixedFraction::times(MixedFraction m){
	fraction f = (toImproper()).times(m.toImproper());

	return MixedFraction(0,0,1);
}

fraction::fraction(){
	n = 0;
	d = 1;
	cout<<"Default Constructor! - Fraction"<<endl;
	ctr++;
}

fraction::fraction(int n, int d){
	this->n = n;
	this->d = d;
	ctr++;
	cout<<"Overloaded Constructor!"<<endl;
}
int fraction::getNumerator(){
	return n;
}
int fraction::getDenominator(){
	return d;
}

void fraction::setNumerator(int x){
	n = x;
}

void fraction::setDenominator(int x){
	d = x;
}

fraction fraction::times(fraction f){
	fraction ans;
	ans.setNumerator(n*f.n);
	ans.setDenominator(d*f.d);
	return ans;
}

void fraction::display(){
	cout<<n<<"/"<<d<<endl;
}
int main(){
	fraction f(2,3), g(3,2), h;
	h = f*g;
	cout<<h<<" "<<f<<endl;
//	h.display();
	return 0;
}
