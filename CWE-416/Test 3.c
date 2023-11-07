#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int *) malloc(sizeof(int));
    free(ptr);
    *ptr = 42;  // Use-After-Free vulnerability
    return 0;
}

// This code demonstrates a Use-After-Free vulnerability in C. The code allocates a block of memory using the malloc function and then frees the memory using the free function. 
// However, the code then continues to access the memory by assigning the value 42 to it. 
// This results in a Use-After-Free vulnerability, as the program is accessing memory that has already been freed.