#include <iostream>

using namespace std;

bool leapyear(int);

int main()
{
    int year = 0;
    cout << "Enter year : ";
    cin >> year;
    leapyear(year);
    cout << "Year is ";
    if(leapyear(year) == false)
        cout << "not ";
    cout << "a leap year";
    return 0;
}

bool leapyear(int year){
    if(year%4) // meaning y%4!=0
        return false;
    if(year%100==0 && year%400)
        return false;
    return true;
}
