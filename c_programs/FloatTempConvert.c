#include <stdio.h>

/*Display Fahrenheit-Celsius table for f = 0,20 ... 300
formula: C = (5/9)(F - 32)
lower is the lower limit of table
upper is upper limit of table
step is the size of increments 

here we declare farh and celsius as floating points
this allows us to use a nicer conversion 
the %6.1f means floating point at least 6 char wide and 1 after decimal point
*/

main()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0; 
    upper = 300;
    step = 20;

    fahr = lower;
    
    while (fahr <= upper){
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n ",fahr,celsius);
        fahr = fahr + step;
    }
}