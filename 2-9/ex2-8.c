/**
 * Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n bit positions.
 */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main() {
    /* test data */
    printf("%o\n", rightrot(010, 4));
}

unsigned rightrot(unsigned x, int n) {
    unsigned mask = ~(~0u >> 1);
    int lastBit;
    for (int i = 0; i < n; ++i) {
        lastBit = x & 1;
        x >>= 1;
        if (lastBit == 1) {
            x |= mask;
        }
    }
    return x;
}
