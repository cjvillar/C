//& Provides the address of something stored in memory.
//  * Instructs the compiler to go to a location in memory.

#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n; //pointer to n, it is just an int of 8 bytes
    printf("This is the memory address: %p\n", p);
    printf("This is what is stored there: %i\n", *p);
    //string
    printf("For the string: \n");
    char *s = "HI!";
    printf("%c", s[0]);
    printf("%c", s[1]);
    printf("%c\n", s[2]);
    printf("Each letter in string is stored: \n");
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}