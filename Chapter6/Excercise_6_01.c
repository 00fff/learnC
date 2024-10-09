#include <stdio.h>

int getword(char *word, int lim)
{
    int c;
    char *w = word;
    while (isspace(c = getch()))  // Skip whitespace
        ;

    // Handle single-line comments (//)
    if (c == '/') {
        int next_c = getch();
        if (next_c == '/') {
            // Skip the rest of the line until a newline or EOF is encountered
            while ((c = getch()) != '\n' && c != EOF)
                ;
            return getword(word, lim);  // Restart after skipping the comment
        } else if (next_c == '*') {  // Handle multi-line comments (/* ... */)
            // Skip everything until the closing */
            while (1) {
                c = getch();
                if (c == EOF) {
                    return EOF;  // End of file, terminate
                }
                if (c == '*') {
                    int next_next_c = getch();
                    if (next_next_c == '/') {
                        break;  // Found the end of the comment
                    } else {
                        ungetch(next_next_c);  // Wasn't a closing /, push back
                    }
                }
            }
            return getword(word, lim);  // Restart after skipping the comment
        } else {
            ungetch(next_c);  // Not a comment, so push the next character back
        }
    }

    // Normal word processing
    if (c != EOF)
        *w++ = c;  // Add the first character
    if (!isalpha(c)) {  // If it's not a letter, return the character
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {  // Keep reading letters or digits
            ungetch(*w);  // Push the last non-letter/digit back
            break;
        }
    }
    *w = '\0';  // Terminate the string
    return word[0];  // Return the first character
}
