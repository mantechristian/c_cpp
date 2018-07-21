#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter an integer : ";
    cin >> n;
    if(n>55 && n<79)
        cout << "You win!" << endl;
    else
        cout << "You lose!" << endl;
    return 0;
}
