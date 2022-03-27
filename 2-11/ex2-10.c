/**
 * Exercise 2-10. Rewrite the function lower, which converts uppoer case
 * letters to lower case, with a conditional expression instead of if-else.
 */

#include <stdio.h>

int lower(int c);

int main() {
    /* test data */
    printf("%c\n", lower('H'));
    printf("%c\n", lower('x'));
}

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
