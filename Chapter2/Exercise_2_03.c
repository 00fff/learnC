#include <stdio.h>
#define MAXLINE 1000

int main(void) 
{
    int c, i = 0, n = 0;  // Initialize i and n
    char hexcode[MAXLINE];

    // Read input from the user
    while ((c = getchar()) != EOF && i < MAXLINE - 1) {
        hexcode[i++] = c;  // Store character
    }
    hexcode[i] = '\0';  // Null-terminate the string

    // Check for optional "0x" or "0X" prefix
    i = 0;  // Reset index for processing
    if (hexcode[0] == '0' && (hexcode[1] == 'x' || hexcode[1] == 'X')) {
        i = 2;  // Skip the "0x" or "0X"
    }

    // Process each hexadecimal character
    for (; hexcode[i] != '\0'; i++) {
        int hex_digit;

        if (hexcode[i] >= '0' && hexcode[i] <= '9') {
            hex_digit = hexcode[i] - '0';  // Convert '0'-'9' to integer (0-9)
        } else if (hexcode[i] >= 'a' && hexcode[i] <= 'f') {
            hex_digit = hexcode[i] - 'a' + 10;  // Convert 'a'-'f' to integer (10-15)
        } else if (hexcode[i] >= 'A' && hexcode[i] <= 'F') {
            hex_digit = hexcode[i] - 'A' + 10;  // Convert 'A'-'F' to integer (10-15)
        } else {
            // Invalid character, stop processing
            break;
        }

        n = 16 * n + hex_digit;  // Multiply by 16 (shift) and add current hex digit
    }

    printf("Integer value: %d\n", n);  // Print the final integer value

    return 0;  // Return 0 to indicate success
}
