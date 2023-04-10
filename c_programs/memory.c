//run on compiled memory
// valgrind ./memory
//valgrind not on macos ventura
//try leaks

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    if (x == NULL)
    {
        return 1;
    }

    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
    //free(x)
    return 0;
}