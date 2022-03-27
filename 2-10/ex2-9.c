/**
 * Exercise 2-9. IN a two's complement number system, x &x (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a faster
 * version of bitcount.
 *
 * Explanation: There are two scenarios.
 *
 * 1. Rightmost bit is 1.
 * x &= (x-1) simply deduct 1 from the rightmost bit.
 * For example, if x in binary form is 10011101, x-1 is then 10011100.
 * x & (x-1) is then 10011100.
 *
 * 2. Rightmost bit is 2.
 * The expression (x-1) will flip all the 0-bits on the right of the rightmost
 * 1-bit, and flip the rightmost 1-bit to 0-bit. It's similar to deduction in
 * a decimal system where 1000 - 1 = 999.
 * For example, if x in binary form is 00111000, x-1 is then 00110111.
 * x & (x-1) is then 00110000.
 */

#include <stdio.h>

int bitcount(unsigned x);

int main() {
    /* test data */
    printf("%d\n", bitcount(0227)); /* 5 */
    printf("%d\n", bitcount(0365)); /* 6 */
}

int bitcount(unsigned x) {
    int count;
    for (count = 0; x != 0; ++count) {
        x &= (x-1);
    }
    return count;
}
