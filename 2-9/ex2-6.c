/**
 * Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position p set to the rightmost n bits of y, leaving the
 * other bits unchanged.
 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
    /* test data */
    printf("%o\n", setbits(0226, 3, 5, 0133)); /* 0356 */
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned maskY = ~(~0 << n);
    unsigned rightY = y & maskY;
    unsigned maskX = rightY << (p-1);
    unsigned clearX = ~(maskY << (p-1));
    x &= clearX;
    x |= maskX;
    return x;
}
