//CMSC 21 Review Class
#include <iostream>

using namespace std;

class Polygon{
protected:
    int width,height;
public:
    Polygon(){cout<<"I am first."<<endl;width=0;height=0;}
    Polygon(int w, int h){width=w;height=h;}
    void setValues(int w, int h){width=w; height=h;}
    void display(){cout<<width<<" "<<height<<endl;}
    friend int area(Polygon);
};

class Rectangle:public Polygon{
public:
    Rectangle():Polygon(){}
    Rectangle(int w,int h){}
    int area(){ return width*height;}
};

class Square:public Rectangle{
public:
    Square():Rectangle(){}
    void setValues(int s){Rectangle::setValues(s,s);}
    int area(){ return width*height;}
};

class Triangle:public Polygon{
public:
    Triangle(){width=1; height=1;}
    void display(){cout<<"I am a triangle! "<<width<<" "<<height<<endl;}
    double area(){return double((height/2)*width);}
};
int area(Polygon);
void change(int &r){
    r = 109;
}


int main(){
    //BigNum b(34), n("123456");
    //BigNum c(b+n);
    //Polygon p(2,4);
    //cout<<area(Polygon(3,4))<<endl;
    int x = 100;
    int &rx = x;
    cout<<&rx<<" "<<&x<<endl;
    change(rx);
    cout<<rx<<" "<<x<<endl;
    Rectangle r(3,4);
    Polygon *p;
    Square s,t;
    Triangle tr;
    r.setValues(3,4);
    s.setValues(6);
    //t.setValues(5,5);
    tr.setValues(7,8); //function overwriting
    tr.display();
    p = &tr;
    p->display();
    return 0;
}

int area(Polygon p){
    return p.width * p.height;
}
