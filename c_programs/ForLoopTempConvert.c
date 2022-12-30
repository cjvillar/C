#include <stdio.h>

/* Here we will use define name value
so we don't have random numbers in our code that will confuse future 
you.

*/

#define LOWER 0 /* lower limit of table */
#define UPPER 300 /* upper limit of table */
#define STEP 20 /* step size */

main(){
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n ", fahr, (5.0/9.0) * (fahr-32));

}