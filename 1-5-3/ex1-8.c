/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

int main() {
    int c, nb, nt, nl;

    for (nb = nt = nl = 0; (c = getchar()) != EOF; ) {
        if (c == ' ') {
            ++nb;
        }
        if (c == '\t') {
            ++nt;
        }
        if (c == '\n') {
            ++nl;
        }
    }

    printf("Number of blanks: %d.\n", nb);
    printf("Number of tabs: %d.\n", nt);
    printf("Number of newlines: %d.\n", nl);

    return 0;
}
