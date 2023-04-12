#include <stdio.h>

int main() {
    int a = 10, b = 20, sum;

    asm ("movl %1, %%eax;"
         "addl %2, %%eax;"
         "movl %%eax, %0;"
         : "=r" (sum)   // output
         : "r" (a), "r" (b) // input
         : "%eax"      // clobbered register
    );

    printf("Sum = %d\n", sum);

    return 0;
}