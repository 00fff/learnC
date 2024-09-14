#include <stdio.h>

#define MAXLINE 1000 /* Maximum input line length */
/* Function declarations */
// int getLine(char line[], int maxline);
// void copy(char to[], char from[]);

/* Main function: print the longest input line */
//     int len;                /* Current line length */
//     int max;                /* Maximum length seen so far */
//     char line[MAXLINE];     /* Current input line */
//     char longest[MAXLINE];  /* Longest line saved here */

//     max = 0;
//     /* Read lines and find the longest one */
//     while ((len = getLine(line, MAXLINE)) > 0) {
//         if (len > max) {
//             max = len;
//             copy(longest, line);
//         }
//     }

//     /* Print the longest line */
//     if (max > 0) { /* There was a line */
//         printf("%s", longest);
//     }

//     return 0;
// }

// /* getLine: read a line into s, return length */
// int getLine(char s[], int lim) {
//     int c, i;

//     /* Read characters until limit is reached, EOF or newline */
//     for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
//         s[i] = c;
//     }

//     /* If the last character was a newline, add it */
//     if (c == '\n') {
//         s[i] = c;
//         ++i;
//     }

//     /* Null-terminate the string */
//     s[i] = '\0';

//     return i; /* Return the length of the line */
// }

// /* copy: copy 'from' into 'to'; assume 'to' is big enough */
// void copy(char to[], char from[]) {
//     int i = 0;

//     /* Copy characters until the null terminator is found */
//     while ((to[i] = from[i]) != '\0') {
//         ++i;
//     }
//Challenge 1

/* Function prototypes */
// int get_line(char line[], int maxline);
// void copy(char to[], char from[]);

// /* Main function: print the longest input line */
// int main() {
//     int len;               /* Current line length */
//     int max;               /* Maximum length seen so far */
//     char line[MAXLINE];    /* Current input line */
//     char longest[MAXLINE]; /* Longest line saved here */

//     max = 0;

//     /* Read lines until EOF */
//     while ((len = get_line(line, MAXLINE)) > 0) {
//         if (len > max) {  /* Check if current line is the longest */
//             max = len;
//             copy(longest, line);
//         }
//     }

//     /* If there was at least one line, print the longest */
//     if (max > 0) {
//         printf("Longest line: %s", longest);
//     }

//     return 0;
// }

// /* get_line: read a line into s, return length */
// int get_line(char s[], int lim) {
//     int c, i;

//     /* Read characters until limit is reached, EOF, or newline */
//     for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
//         s[i] = c;
//     }

//     /* If newline is encountered, include it in the string */
//     if (c == '\n') {
//         s[i] = c;
//         ++i;
//     }

//     /* Null-terminate the string */
//     s[i] = '\0';

//     return i; /* Return the length of the line */
// }

// /* copy: copy 'from' into 'to'; assume 'to' is big enough */
// void copy(char to[], char from[]) {
//     int i = 0;

//     /* Copy each character from 'from' to 'to' until '\0' */
//     while ((to[i] = from[i]) != '\0') {
//         ++i;
//     }
// }
// Challenge 2
#include <stdio.h>

#define MAXLINE 1000  // Define a maximum size for the array

int main() {
    int c, count = 0, i, j;
    char array2[MAXLINE];  // Array to hold input characters

    // Read characters until EOF
    while ((c = getchar()) != EOF) 
        if (c == '\t')
            continue;
        if (count < MAXLINE - 1) {
            // Ensure we don't exceed array bounds
            array2[count] = c;   // Store the character in the array
            count++;
            printf("%d ", count);
            putchar('\n');
        // Print the index and character stored in the arra
        }  


    return 0;
}
