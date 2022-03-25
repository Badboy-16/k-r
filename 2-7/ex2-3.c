/**
 * Exercise 2-3. Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 */

#include <stdio.h>

int htoi(char s[]);

int main() {
    /* Test data */
    printf("0xa1e: %d\n", htoi("0xa1e"));
    printf("0X4FB: %d\n", htoi("0X4FB"));
    printf("c3: %d\n", htoi("c3"));
    printf("58A: %d\n", htoi("58A"));
    printf("f: %d\n", htoi("f"));
    return 0;
}

int htoi(char s[]) {
    int i, c, n;
    n = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
    } else {
        i = 0;
    }
    while ((c = s[i]) != '\0') {
        if (c >= '0' && c <= '9') {
            n = 16 * n + c - '0';
        } else if (c >= 'a' && c <= 'f') {
            n = 16 * n + c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            n = 16 * n + c - 'A' + 10;
        }
        ++i;
    }
    return n;
}
