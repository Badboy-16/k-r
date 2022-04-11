/* Exercise 1-21. Write a program entab that replaces strings of blanks by
    the minimum number of tabs and blanks to achieve the same spacing. Use
    the same tab stops as for detab. When either a tab or a single blank
    would suffice to reach a tab stop, which should be given preference? */

#include <stdio.h>

#define TABS 8 /* tabstop */
#define IN 1 /* in string of blanks */
#define OUT 0 /* out of string of blanks */

void entab(void);

int main()
{
    entab();
    return 0;
}

void entab(void)
{
    int nc = 0; /* number of characters read on the line */
    int nb = 0; /* number of blanks in the string of blanks */
    int nrt = 0; /* number of replacement tabs */
    int c;
    int state = 0; /* in or out of string of blanks */

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            if (state == OUT)
                state = IN;
            if (c == ' ') {
                nb++;
                nc++;
            } else if (c == '\t') {
                nb += TABS - nc % TABS;
                nc += TABS - nc % TABS;
            }
        } else {
            if (state == IN) {
                state = OUT;
                nrt = nc / TABS - (nc - nb) / TABS;
                for (int i = 0; i < nrt; i++)
                    putchar('\t');
                if (nrt)
                    for (int i = 0; i < nc % TABS; i++)
                        putchar(' ');
                else
                    for (int i = 0; i < nb; i++)
                        putchar(' ');
                nb = 0;
            }
            putchar(c);
            nc++;
            if (c == '\n')
                nc = nb = nrt = 0;
        }
    }
}
