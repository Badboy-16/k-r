/* Exercise 1-9. Write a program to copy its input to its output, replacing each
string of one or more blanks by a single blank */

#include <stdio.h>

#define IN 1 /* inside string of blanks */
#define OUT 0 /* outside string of blanks */

int main() {
    int state = OUT;
    for (int c; (c = getchar()) != EOF; ) {
        if (c == ' ') {
            if (state == OUT) {
                state = IN;
                putchar(c);
            }
        }
        if (c != ' ') {
            if (state == IN) {
                state = OUT;
            }
            putchar(c);
        }
    }

    return 0;
}
