/* Exercise 4-12. Adapt the ideas of printd to write a recursive version of
    itoa; that is, convert an integer into a string by calling a recursive
    routine. */

#include <stdio.h>
#define LIMIT 32
#define TESTDATA 65536

void itoa(int, char[]);
int idx = 0;

int main()
{
    /* test data */
    char array[LIMIT];
    itoa(TESTDATA, array);
    for (int i = 0; array[i] != '\0'; i++)
        putchar(array[i]);
    return 0;
}

void itoa(int n, char a[])
{
    if (n < 0) {
        a[idx++] = '-';
        n = -n;
    }
    if (n / 10)
        itoa(n / 10, a);
    a[idx++] = n % 10 + '0';
    if (n == 0)
        a[idx] = '\0';
}
