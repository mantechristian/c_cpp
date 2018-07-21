#include<stdio.h>

int multiply(int  , int );

main()
{
    int a , b , product;
    printf("\n Enter numbers:");
    scanf("%d%d",&a,&b);
    product = multiply(a,b);
    printf("\n\n The product of the two numbers is: %d",product);

    return 0;
}


int multiply(int a, int b)
{
    static int product=0, count=0;

    if(count<a){

        product+=b;
        count++;
        multiply(a,b);

    }
    return product;
}
