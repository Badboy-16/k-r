#include <stdio.h>

/* print Fahrenheit-Celsius table */
int main()      /* added return type */
{
    int fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)   /* modified */
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));

    return 0;   /* added return value */
}
