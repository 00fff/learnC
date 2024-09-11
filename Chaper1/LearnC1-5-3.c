#include <stdio.h>

/* copy input to output, replacing each sequence of blanks with a single blank */
int main()
{

    // Challenege 1
    // int c;            // Variable to store the current character
    // int last_char_was_blank = 0; // Flag to track if the last character was a blank space

    // // Read characters from input until EOF
    // while ((c = getchar()) != EOF) {
    //     // Check if the current character is a blank space
    //     if (c == ' ') {
    //         // If the last character was also a blank, skip this one
    //         if (last_char_was_blank) {
    //             continue;
    //         }
    //         // Otherwise, output a single blank space
    //         putchar(c);
    //         last_char_was_blank = 1; // Set flag indicating the last character was a blank
    //     } else {
    //         // Output the current character
    //         putchar(c);
    //         last_char_was_blank = 0; // Reset the flag since the current character is not a blank
    //     }
    // }

    // return 0;

    //Challenge 2
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\b') {
            printf("\b"); 
            }
        if (c == '\t') {
            printf("\\t");
        }
        }
        putchar(c);
    }
