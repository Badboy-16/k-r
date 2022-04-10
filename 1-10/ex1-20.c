/* Exercise 1-20. Write a program detab that replaces tabs in the input
    with the proper number of blanks to space to the next tab stop. Assume
    a fixed set of tab stops, say every n columns. Should n be a variable
    or a symbolic parameter? */

#include <stdio.h>

#define TABSTOP 8

void detab(void);

int main()
{
    detab();
    return 0;
}

void detab(void)
{
    int nc = 0; /* number of characters on the line */
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            nc = 0;
        } else if (c == '\t') {
            for (int i = 0; i < TABSTOP - nc % TABSTOP; i++)
                putchar(' ');
            nc += TABSTOP - nc % TABSTOP;
        } else {
            putchar(c);
            nc++;
        }
    }
}
