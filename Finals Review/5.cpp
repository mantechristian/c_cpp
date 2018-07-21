#include <iostream>

using namespace std;

int main(){
    int a = 0 , b = 0 , c = 0, x= 0;
    cout << "Enter your numbers : ";
    cin >> a >> b >> c;
    cout << "In proper order : "<< a << " " << b << " " << c << endl;
    x = a%10;
    x*=10;
    a = a/10;
    a+=x;
    x = b%10;
    x*=10;
    b = b/10;
    b+=x;
    x = c%10;
    x*=10;
    c = c/10;
    c+=x;
    cout << "In reverse order : " << a << " "<< b << " "<< c << endl;
    return 0;
}
