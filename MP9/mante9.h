#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iomanip>
using namespace std;

class Ballpen{
    private:
        string brand;
        string color;
        float inkLevel;
    public:
        Ballpen();
        ///Ballpen(string b, int c, Ballpen pen);
        string getbrand();
        string getcolor();
        void setbrand(string b);
        void setcolor(int c);
        float get_inkLevel();
        void refill();
        void write(string s);
        string erase(int n, string s);
};
