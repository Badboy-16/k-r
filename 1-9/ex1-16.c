/**
 * Exercise 1-16. Revise the main routine of the longest-line program so it
 * will correctly print the length of arbitrarily long input lines, and as much
 * as possible of the text.
 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len;            /* current line length */
    int max;            /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */
    int tempc;          /* used for getchar for longer lines */

    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0) {
        if (line[len-1] != '\n') {
            while ((tempc = getchar()) != '\n' && tempc != EOF) {
                ++len;
            }
            ++len;
        }
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)    /* there was a line */
        printf("%s\n", longest);
        printf("%d\n", max);
    return 0;
}

/* mygetline:  read a line into s, return length */
int mygetline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
