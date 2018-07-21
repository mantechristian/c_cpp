#include <iostream>
using namespace std;

void fib(int);

main(){
    int n;
    cin >> n;
    fib(n);
    return 0;
}

void fib(int n)
{
    int first = 1, second = 1, next = 0;
    for (int i = 1 ; i <= n-2 ; i++ )
    {
        next = first + second;
        first = second;
        second = next;
    }
    cout << second;
}
