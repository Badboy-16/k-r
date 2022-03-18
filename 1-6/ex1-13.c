/**
 * Exercise 1-13. Write a program to print a histogram of the lengths of words
 * in its input. It is easy to draw the histogram with the bars horizontal; a
 * vertical orientation is more challenging.
 */

#include <stdio.h>

#define IN  1
#define OUT 0
#define BAR 10 /* number of bars in the histogram */

int main() {
    int c, state, len;
    int lengths[BAR] = {0}; /* lengths of words */
    state = OUT;
    len = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state = IN) {
                state = OUT;
                ++lengths[len-1];
                len = 0;
            }
        } else {
            ++len;
        }
    }

    /* horizontal version */
    for (int l = 0; l < BAR; ++l) {
        if (l == BAR - 1) {
            printf("%2d+:", l+1);
        } else {
            printf("%3d: ", l+1);
        }
        for (int w = 0; w < lengths[l]; ++w) {
            printf("-");
        }
        printf("\n");
    }

    /* vertical version */
    int max = 0; /* maximum word length */
    for (int l = 0; l < BAR; ++l) {
        if (lengths[l] > max) {
            max = lengths[l];
        }
    }
    int thres = max;
    for (int t = thres; t > 0; --t) {
        for (int l = 0; l < BAR; ++l) {
            if (lengths[l] >= t) {
                printf("   -");
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
    for (int l = 0; l < BAR; ++l) {
        if (l == BAR - 1) {
            printf("%3d+", l+1);
        } else {
            printf("%4d", l+1);
        }
    }
    printf("\n");

    return 0;
}
