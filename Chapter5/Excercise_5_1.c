#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100

int getch(void);
void ungetch(int);
/* getch: get a (possibly pushed back) character */

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0;      // next free position in buf
/* ungetch: push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))   /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);   /* it is not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        int next = getch();  // Get the next character after '+' or '-'
        if (!isdigit(next))  {
            ungetch(next);
            ungetch(c);
        }
        c = next;  // Proceed with the digit after '+' or '-'
    }
        

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}
