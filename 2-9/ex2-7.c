/**
 * Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged.
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
    /* test data */
    printf("%o\n", invert(0226, 3, 5)); /* 0352 */
}

unsigned invert(unsigned x, int p, int n) {
    unsigned mask = (~(~0 << n)) << (p-1);
    x ^= mask;
    return x;
}
