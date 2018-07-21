/*I, Christian R. Mante, upon my honor, do solemnly swear that I have made this MP all by myself.
  This program attempts to perform operations on thousand digit integers and display them.
*/

#include <iostream>
using namespace std;

class BigNum{
private:
    int digit[1001];//exactly a thousand digits
public:
    BigNum();//constructor
    BigNum(int);//overloaded constructor
    BigNum(string);//overloaded constructor
    BigNum operator+(BigNum);//overloaded operator +
    BigNum operator-(BigNum);//overloaded operator -
    BigNum operator*(BigNum);//overloaded operator *
    BigNum operator/(BigNum);//overloaded operator /
    BigNum operator%(BigNum);//overloaded operator %
    int getdigit(BigNum, int);//getter
};

int BigNumToInt(BigNum);
BigNum fib(int);
void display(BigNum);

//#include "manteMPA6.cpp"
main(){
    cout << "101th Fibonacci"<<endl;
    cout << "Scroll sidewards please --->" <<endl;
    display(fib(101)); //101th is 573147844013817084101
    BigNum n1(1000), n2(1), n3;
    n3 = n1 - n2;
    cout << endl << "Subtraction : " << endl;
    display(n3);
    cout << endl << "Multiplication : " << endl;
    BigNum n4(25), n5(25), n6;
    n6 = n4 * n5;
    display(n6);
    return 0;
}

BigNum::BigNum(){ //init int array to zero
    for(int i = 0; i < 1001; i++){
        digit[i] = 0;
    }
}

BigNum::BigNum(int num){//init given int
    int i = 0, j = 0;
    for(; i < 1001; i++){//init int array to 0
        digit[i] = 0;
    }

    for(i = 1000; i>= 0; i--){//int to BigNum
        digit[i] = num % 10;
        num /= 10;
    }
}

BigNum::BigNum(string num){ //initialize given string
    int i = 0, j = 0, foo = 0;
    for(; i < 1001; i++){ //set int array to zero
      digit[i] = 0;
    }

    for(i = 0; num[i] != '\0'; i++){ //foo gets the number of integer digits the string has
        if(!(num[i] >= '0' && num[i] <= '9')){
            cout << "\nInvalid input.\n";
        }
        foo++;
    }
    foo-=1;
    for(j = 1000; foo >= 0 ; foo--, j--){ //put last integer element of string to last element of digit array of BigNum
        num[foo] -= '0';
        digit[j] = num[foo];
    }
}

BigNum BigNum::operator+(BigNum num){
    BigNum sum;
    int carry = 0;
    for(int i = 1000; i >= 0 ;i--){
        sum.digit[i] = (this->digit[i] + num.digit[i] + carry);
        carry = 0;
        if(sum.digit[i] > 9){
            carry = sum.digit[i] / 10;
            sum.digit[i] = sum.digit[i] % 10;
        }
    }
    return sum;
}

BigNum BigNum::operator-(BigNum num){
    BigNum diff;
    for(int i = 1000; i>=0 ;i--){
        if(this->digit[i] < num.digit[i]){
            this->digit[i]+=10;
            this->digit[i-1]-=1;//borrow
        }
        diff.digit[i] = (this->digit[i] - num.digit[i]);
        }
    return diff;
}

BigNum BigNum::operator*(BigNum num){
    BigNum product, sum;
    int carry = 0, x = 1000, store = 0;
    for(int i = 1000, k = 0; i >= 0; i--, k++){ // i = index of multiplier
        for(int j = 1000; j >= 0; j--){ // j = index of multiplicand
             // this = multiplicand, num = multiplier
            product.digit[j] = this->digit[j] * num.digit[i] + carry;
            carry = 0;
            carry = product.digit[j] / 10;
            product.digit[j] = product.digit[j] % 10;
        }
        sum = sum + product;
        x=0;
        while(x<=1000){
            sum.digit[x]=sum.digit[x-1];
            x--;
        }
    }
    return sum;
}

/*
BigNum BigNum::operator/(BigNum num){
    int i = 0, j = 0;
    bool isfound1 = false, isfound2 = false;
    while(this->digit[i] < 1){ ///find first nonzero digit
        i++;
    }
    isfound1 = true;
    while(num.digit[j] < 1){
        j++;
    }
    isfound2 = true;
    for(;;){

    }

}*/

BigNum fib(int n){
    BigNum first(1), second(1), next;
    for (int i = 1 ; i <= n-2 ; i++ )
    {
        next = first + second;
        first = second;
        second = next;
    }
    return second;
}

int BigNum::getdigit(BigNum next,int i){
    return next.digit[i];
}

void display(BigNum num){
    int store[1001];
    for(int i = 0; i < 1001; i++){
        store[i] = num.getdigit(num,i);
        cout << store[i];
    }
    cout << endl << endl;
}

