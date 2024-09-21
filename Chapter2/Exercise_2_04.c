#include <stdio.h>

int main(void) {
    int i, j, k;
    char string1[10] = {'A', 'B', 'C', 'D', 'E', '\0'};
    char string2[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', '\0'};  // Ensure proper size

    // Loop through each character in string2
    for (i = 0; string2[i] != '\0'; i++) {
        for (j = 0; string1[j] != '\0'; j++) {
            // If a character from string2 matches string1, break
            if (string2[i] == string1[j]) {
                break;
            }
        }
        // If we reached the end of string1 without finding a match
        if (string1[j] == '\0') {
            string1[k++] = string2[i];  // Keep the character from string2
        }
    }
    string1[k] = '\0';  // Null-terminate the modified string

    printf("Modified string1: %s\n", string1);  // Print the modified string1
    return 0;
}
