#include <stdio.h>

int main(){
    printf("Enter a number: ");  

    int number;
    // reads and stores input
    scanf("%d", &number);
    int *pNumber = &number;

    //a pointer holds the memory adress of a var
    printf("The address of the number is: %p\n", &number);
    printf("The value of the number is: %p\n",pNumber);

    printf("The size of the number is: %lu bytes\n", sizeof(number));
    printf("The size of the pointer number is: %lu bytes\n", sizeof(pNumber));

    printf("The value of the number is: %d\n", number);
    printf("The value of the pointer is: %d \n", *pNumber);
    
    return 0;
}
