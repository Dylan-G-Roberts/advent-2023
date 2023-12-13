#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch())) /* skip whitespace */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '=') {
        ungetch(c); /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch();
    return c;
}

int main() {
    int n, array[SIZE], getint(int *);

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;
}