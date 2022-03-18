/**
 * Exercise 1-14. Write a program to print a histogram of the frequencies of
 * different characters in its input.
 */

#include <stdio.h>

#define CS 128 /* number of characters in the character set */

int main() {
    int c;
    int chars[128] = {0};

    while ((c = getchar()) != EOF) {
        ++chars[c];
    }

    for (int i = 0; i < CS; ++i) {
        printf("%10c:", i);
        for (int n = 0; n < chars[i]; ++n) {
            printf("-");
        }
        printf("\n");
    }

    return 0;
}
