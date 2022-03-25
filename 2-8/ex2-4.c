/** Exercise 2-4. Write an alternate version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in the string s2.
 */

#include <stdio.h>

#define IN 1
#define OUT 0

void squeeze(char s1[], char s2[]);

int main() {
    /* test data */
    char s1[] = "hello, world";
    char s2[] = "lo";
    squeeze(s1, s2);
    printf("%s\n", s1);
}

void squeeze(char s1[], char s2[]) {
    int oldIdx, newIdx, s2Len, state;
    for (s2Len = 0; s2[s2Len] != '\0'; ++s2Len) {
        ;
    }
    oldIdx = newIdx = 0;
    state = OUT;
    while (s1[oldIdx] != '\0') {
        for (int i = 0; i < s2Len; ++i) {
            if (s1[oldIdx] == s2[i]) {
                state = IN;
                break;
            }
        }
        if (state == OUT) {
            s1[newIdx++] = s1[oldIdx++];
        } else if (state == IN) {
            ++oldIdx;
        }
        state = OUT;
    }
    s1[newIdx] = '\0';
}
