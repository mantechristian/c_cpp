#include <stdio.h>

int summation(int);
int SoD(int,int);
int main(){
    int x = SoD(12345,0);
    return 0;
}

int summation(int n){
    if(n==1)
        return 1;
    else
        return n + summation(n-1);
}

int SoD(int n){
    if(n<10)
        return n;
    else
        return n%10 + SoD(n/10);
}
