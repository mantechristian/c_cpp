/*Lets try: Fizzbuzz*/
#include<stdio.h>
main()
{
    int n=1;
    for(;n<=100;n++){
        if((n%3==0)&&(n%5==0))
            printf("\n%d Fizzbuzz",n);
        else if(n%3==0)
            printf("\n%d Fizz",n);
        else if(n%5==0)
            printf("\n%d Buzz",n);
        else
            printf("\n%d",n);
    }
    return 0;
}
