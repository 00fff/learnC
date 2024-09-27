#include <stdio.h>
#include <ctype.h>

int getfloat(float *pn) {
    int c, sign;
    float value = 0.0;   // Initialize value for the floating point number
    float divisor = 1.0; // For handling the fractional part
    int decimal_point_seen = 0; // Flag for checking decimal point

    // Skip whitespace
    while (isspace(c = getchar()))
        ;

    // Handle optional sign
    if (c == '-' || c == '+') {
        sign = (c == '-') ? -1 : 1;
        c = getchar(); // Read the next character
    } else {
        sign = 1; // Default to positive
    }

    // Parse the number
    while (1) {
        if (isdigit(c)) {
            if (decimal_point_seen) {
                // Process fractional part
                value += (c - '0') / (divisor *= 10); // Update divisor
            } else {
                // Process integer part
                value = value * 10 + (c - '0');
            }
        } else if (c == '.') {
            if (decimal_point_seen) {
                break; // Invalid input: two decimal points
            }
            decimal_point_seen = 1; // Set flag for decimal point
        } else {
            break; // Break on non-digit character
        }
        c = getchar(); // Read the next character
    }

    // Apply the sign to the final value
    *pn = sign * value;

    // Return 1 if we processed at least one valid digit
    return (c != EOF) || (isdigit(c));
}

int main(void) {
    float number;

    printf("Please enter a floating-point number: ");

    if (getfloat(&number)) {
        printf("You entered the number: %f\n", number);
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}
