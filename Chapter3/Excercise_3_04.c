#include <stdio.h>
#include <string.h>

/* Function to reverse the string */
void reverse(char s[]) {
    int i = 0, j = strlen(s) - 1;
    char temp;
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        // Move indices towards the center
        i++;
        j--;
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
    int i = 0, sign;

    if ((sign = n) < 0) { // Record sign
        n = -n; // Make n positive
    }

    do { // Generate digits in reverse order
        s[i++] = n % 10 + '0'; // Get next digit
    } while ((n /= 10) > 0); // Delete it

    if (sign < 0) {
        s[i++] = '-'; // Add minus sign for negative numbers
    }

    s[i] = '\0'; // Null-terminate the string
    reverse(s); // Reverse the string to get correct order
}

int main() {
    int n = 123;
    char s[10];
    itoa(n, s);
    printf("Converted integer to string: %s\n", s); // Print the resulting string
    return 0;
}
