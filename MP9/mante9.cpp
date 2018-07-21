#include "mante9.h"

bool defective_pen();
void show(string s);

Ballpen::Ballpen(){ // constructor
    brand = "Kilometrico";
    color = "blue";
    inkLevel = 20.00;
    return;
}

/*Ballpen::Ballpen(string b, int c, Ballpen pen){ // overloaded constructor
    pen.set_brand(b);
    pen.set_color(c);
    return;
}*/

void Ballpen::setbrand(string b){ // mutator
    brand = b;
    return;
}

void Ballpen::setcolor(int c){ // mutator
    switch(c){
        case 1:
            system("color FC");
            color = "red";
            break;
        case 2:
            system("color F9");
            color = "blue";
            break;
        case 3:
            system("color F6");
            color = "yellow";
            break;
        default:
            break;
    }
    return;
}

void Ballpen::refill(){
    inkLevel = 20.00;
    return;
}

string Ballpen::getbrand(){
    return brand;
}

string Ballpen::getcolor(){
    return color;
}

float Ballpen::get_inkLevel(){
    return inkLevel;
}

void Ballpen::write(string s){
    int i = 0;
    while(s[i]!='\0'){
        if(s[i]!=' '){
            inkLevel -= .1;
            if(inkLevel - .1 <= 0){
                cout << "\n*System : Ran out of ink!*" << endl;
                getch();
                return;
            }
        }

        cout << s[i];
        i++;
    }
    return;
}

string Ballpen::erase(int n, string s){
    int i = 0, size = 0, pos = 0;
    if(s.empty()){
        cout<<"Nothing to erase!\n";
        return s;
    }
    while(s[size]!='\0')
        size++;
    pos = size-n; // pos is the nth character we start deleting from
    s.erase(pos,n);//delete from pos to n, n is the number of characters to be deleted
    cout << "\nWhat's left is : ";
    for(;s[i] != '\0' ;i++){
        cout << s[i];
        if(s[i]!=' '){
            inkLevel -= .2;
                if(inkLevel - .2 <= 0){
                    cout << "\n*System : Ran out of ink!*" << endl;
                    getch();
                    return s;
                }
        }
    }
    return s;
}

bool defective_pen(){
    srand(time(NULL));
    int i = 1 + rand () % 1000;
    if(i == 7)//unlucky number 7, a defective pen
        return true;
    else
        return false;
}

void show(string s){
    int i = 0;
    while(s[i]!='\0'){
        cout<< s[i];
        i++;
    }
    return;
}
