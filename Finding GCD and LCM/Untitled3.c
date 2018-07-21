#include<stdio.h>

main()
{
    int a,b,x,y,t,lcm,gcd;
    printf("Enter x and y: ");
    scanf("%d%d",&x,&y);

    a=x;
    b=y;

    while(b!=0)
    {
        t=b;
        b=a%b;
        a=t;
    }

    gcd=a;
    lcm=(x*y)/gcd;

    printf("The GCD of %d and %d is : %d",x,y,gcd);
    printf("\nThe LCM of %d and %d is : %d",x,y,lcm);
}
