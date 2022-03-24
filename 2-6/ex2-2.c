/**
 * Exercise 2-2. Write a loop equivalent to the for loop above without using &&
 * or ||.
 */

#include <stdio.h>

#define LIM 80

int main() {
    int i = 0;
    while (i < LIM - 1) {
        if ((c = getchar()) != '\n') {
            if (c != EOF) {
                s[i] = c;
                ++i;
            }
        }
    }
    return 0;
}
