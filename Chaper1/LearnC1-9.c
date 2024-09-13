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

int num;
int c, i=0;
int size;
char current[MAXLINE];
char most[MAXLINE];
int get_size(char array[]);
/* Function definitions */
int get_size(char array[]) {
    int i = 0;
    while (array[i] != '\0') {
        i++;
    }
    
    return i;
}

int main() {
while ((c = getchar()) != EOF && c !='\n') {
        current[i] = c;
        i++;
    } 
    size =  get_size(current);
    printf("%d ", size);
}
    


