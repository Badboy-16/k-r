/**
 * Exercise 2-5. Write the function any(s1,s2), which returns the first
 * location in the string s1 where any character from the string s2 occurs, or
 * -1 if s1 contains no characters from s2. (The standard library function
 * strpbrk does the same job but returns a pointer to the location.)
 */

#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
    /* test data */
    char s1[] = "hello, world";
    char s2[] = "lo";
    char s3[] = "c programming language";
    char s4[] = "xyz";
    printf("%d\n", any(s1, s2));
    printf("%d\n", any(s3, s4));
}

int any(char s1[], char s2[]) {
    int location = 0;
    int s2Len = 0;
    while (s2[s2Len] != '\0') {
        ++s2Len;
    }
    while (s1[location] != '\0') {
        for (int i = 0; i < s2Len; ++i) {
            if (s1[location] == s2[i]) {
                return location;
            }
        }
        ++location;
    }
    return -1;
}
