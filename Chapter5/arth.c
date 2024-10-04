#include <stdio.h>
#include <stdlib.h>  // For atoi

int main(int argc, char *argv[]) {
    int stack[1000]; // Stack for numbers
    int pos = 0;     // Current position in stack
    int final = 0;   // Final result

    while (--argc > 0) {
        char *arg = argv[argc]; // Get the command-line argument

        // Check if the argument is a number
        int c_value = atoi(arg); // Convert argument to integer

        // Check if the argument is a number (including zero)
        if (c_value != 0 || (arg[0] == '0' && arg[1] == '\0')) {
            stack[pos++] = c_value; // Push number onto stack
        } else {
            // Handle operators
            if (arg[0] == '*') {
                if (pos >= 2) { // Ensure there are at least two numbers
                    final = stack[pos - 2] * stack[pos - 1]; // Multiply top two numbers
                    stack[pos - 2] = final; // Store result back on the stack
                    pos--; // Decrement position
                } else {
                    printf("Error: Not enough values in stack for multiplication\n");
                }
            } else if (arg[0] == '+') {
                if (pos >= 2) {
                    final = stack[pos - 2] + stack[pos - 1]; // Add top two numbers
                    stack[pos - 2] = final; // Store result back on the stack
                    pos--; // Decrement position
                } else {
                    printf("Error: Not enough values in stack for addition\n");
                }
            } else if (arg[0] == '-') {
                if (pos >= 2) {
                    final = stack[pos - 2] - stack[pos - 1]; // Subtract top two numbers
                    stack[pos - 2] = final; // Store result back on the stack
                    pos--; // Decrement position
                } else {
                    printf("Error: Not enough values in stack for subtraction\n");
                }
            } else if (arg[0] == '/') {
                if (pos >= 2) {
                    if (stack[pos - 1] != 0) { // Ensure no division by zero
                        final = stack[pos - 2] / stack[pos - 1]; // Divide top two numbers
                        stack[pos - 2] = final; // Store result back on the stack
                        pos--; // Decrement position
                    } else {
                        printf("Error: Division by zero!\n");
                        return 1; // Exit if division by zero
                    }
                } else {
                    printf("Error: Not enough values in stack for division\n");
                }
            }
        }
    }

    // Print the final result if the stack is not empty
    if (pos > 0) {
        printf("Final result: %d\n", stack[0]); // Print the final result
    } else {
        printf("No valid calculations performed.\n");
    }

    return 0;
}
