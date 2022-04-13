/* Exercise 5-10. Write the program expr, which evaluates a reverse Polish
    expression from the command line, where each operator or operand is a
    separate argument. For example,

    expr  2  3  4  +  *

    evaluates 2 × (3+4). */

#include <stdio.h>
#include <stdlib.h>

#define MAX 32

void expr(int argc, char *argv[])
{
    double stack[MAX];
    int stacki = 0;
    char * arg;
    double result;

    if (argc < 2) {
        printf("Usage: expr reverse-Polish-expression\n");
    } else {
        while (--argc > 0) {
            arg = *++argv;
            if (isoperand(arg)) {
                if (arg == "+") {
                    result = stack[stacki-1] + stack[stacki-2];
                } else if (arg == "-") {
                    result = stack[stacki-1] - stack[stacki-2];
                } else if (arg == "*") {
                    result = stack[stacki-1] * stack[stacki-2];
                } else if (arg == "/") {
                    result = stack[stacki-1] / stack[stacki-2];
                }
                stack[stacki-2] = result;
                stacki--;
            } else {
                stack[stacki++] = atof(arg);
            }
        }
        printf("Result: %g\n", stack[0]);
    }
}

int isoperand(char a[]) {
    return (a == "+" || a == "-" || a == "*" || a == "/") ? 1 : 0;
}
