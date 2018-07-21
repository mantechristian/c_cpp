#include <stdio.h>
#include <stdlib.h>
int main(){
	int x = 13, y = 19, z = 2;
	int *xptr = &x, *yptr = &y, *zptr = &z;

	printf("%p %p %p\n",xptr,yptr,zptr);
	printf("%d %d %d\n",*xptr,*yptr,*zptr);
    system("pause");

	x = x -7;
	y = x + z;
	z = y - 10;

	printf("%d %d %d\n",*xptr,*yptr,*zptr);
    system("pause");
	*xptr = *zptr + 2;
	*yptr = x + *xptr;
	*zptr = z + *yptr;

    printf("%d %d %d\n",*xptr,*yptr,*zptr);
    printf("%d %d %d\n",x,y,z);
	system("pause");

	xptr = zptr;
	*xptr = 109;

	printf("%d\n",x);
	return 0;
}
