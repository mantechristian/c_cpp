#include <iostream>
using namespace std;

class BigNum{
private:
    int digit[1001];
public:
    BigNum();
    BigNum(int);
    BigNum(string);
    BigNum operator+(BigNum);
    BigNum operator-(BigNum);
    BigNum operator*(BigNum);
    BigNum operator/(BigNum);
    BigNum operator%(BigNum);
    int getdigit(BigNum, int);
};
