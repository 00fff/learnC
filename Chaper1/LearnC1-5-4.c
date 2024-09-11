#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* Count lines, words, and characters in input */
int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    // Read characters from input until EOF
    while ((c = getchar()) != EOF) {
    if (c != ' ') {
        putchar(c);
    } else if (c == ' ')
        putchar('\n');
    }

}
