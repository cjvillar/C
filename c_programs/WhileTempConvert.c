#include <stdio.h>

/*Display Fahrenheit-Celsius table for f = 0,20 ... 300
formula: C = (5/9)(F - 32)
lower is the lower limit of table
upper is upper limit of table
step is the size of increments 
*/

main()
{
    int fahr, celsius;
    int lower, upper, step;
    lower = 0; 
    upper = 300;
    step = 20;

    fahr = lower;
    
    while (fahr <= upper){
        celsius = 5 * (fahr - 32) /9;
        printf("%d\t%d\n",fahr,celsius);
        fahr = fahr + step;
    }
}