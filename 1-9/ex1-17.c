/**
 * Exercise 1-17. Write a program to print all input lines that are longer than
 * 80 characters.
 */

#include <stdio.h>

#define LONG 80

int main() {
    int len = 0;
    int c;
    char str[LONG] = {0};

    while ((c = getchar()) != EOF) {
        str[len] = c;
        ++len;
        if (len == LONG) {
            if (str[len-1] != '\n') {
                for (int i = 0; i < LONG; ++i) {
                    putchar(str[i]);
                }
                while ((c = getchar()) != '\n') {
                    putchar(c);
                }
                putchar(c);
            }
            len = 0;
        } else if (c == '\n') {
            len = 0;
        }
    }

    return 0;
}
