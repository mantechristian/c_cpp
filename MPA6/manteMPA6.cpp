#include "manteMPA6.h"

int BigNumToInt(BigNum);
BigNum fib(int);
void display(BigNum);

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
        if((this->digit[i] + num.digit[i] + carry) > 9){
            carry = sum.digit[i] / 10;
            sum.digit[i] = sum.digit[i] % 10;
        }
    }
    return sum;
}

/*BigNum BigNum::operator-(BigNum num){
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
    BigNum product;
    int carry = 0, sum[1000], store = 0;
    for(int i = 1000; i >= 0; i--){ ///j = multiplicand i = multiplier
        for(int j = 0; j >= 0; j--){
            product.digit[i] = this->digit[j] * num.digit[i] + carry;
            product.digit[i] = product.digit[i] % 10;
            carry = product.digit[i] / 10;
        }
        sum[i] = BigNumToInt(product);
    }
    for(int i = 0, j = 1;i<=1000;i++, j*=10){
        sum[i] *= j;
        store += sum[i];
    }
    BigNum product2(store);
    return product2;
}

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

/*int BigNumToInt(BigNum product){
    int store = 0;
    for(int i = 0; i<=1000; i++){
        store += product.getdigit(product,i);
        store*=10;
    }
}*/

void display(BigNum num){
    int store[1001];
    for(int i = 0; i < 1001; i++){
        store[i] = num.getdigit(num,i);
        cout << store[i];
    }
    cout << endl << endl;
}

