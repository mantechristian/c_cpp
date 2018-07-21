#include <stdio.h>
#include <stdlib.h>

main()
{
    int n=0, i=0;

    printf("Enter size of array : ");
    scanf("%d",&n);
    int *A = (int*)malloc(n*sizeof(int)); ///dynamically allocated array of size n
     ///we could also use (int *)calloc(n,sizeof(int)), calloc initialized all elements to zero
     ///we could aswell use realloc to modify the size of the memory block we requested from the heap
     ///ex: int *B = (int*)realloc(A,2*n*sizeof(int))
     ///the example above creates a new memory block of size 2n and copy the values in the previous block A into the new memory block
     ///realloc syntax : int *new pointer = (int*)realloc(previous pointer, size of new block)
     ///(int*) is used in typecasting to prevent compilation errors
    for(;i<n;i++)
    {
        A[i] = i+1;
        printf("%d ",A[i]);
        if(A[i]%5 == 0)
            printf("\n"); ///You should read and write to an address only if that address is allocated to you
    }
    int *B = (int*)realloc(A, 2*n*sizeof(int));
    printf("\nPrevious block address : %p\nNew block address : %p",A,B); ///A and B now have same values
    free(A); /// A = (int*)realloc(A, 0) is equivalent to free(A)
    free(B); /// int *B = (int*)realloc(NULL, n*sizeof(int)) is equivalent to a malloc
    return 0;
}
