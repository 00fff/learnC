#include <stdio.h>
int expand(char s1[], char s2[]) {
    int c, i = 0, j = 0;
    while (s1[i] != '\0') {
        if (s1[i+1] == '-' && s1[i+2] >= s1[i])
            for (c = s1[i]; c <= s1[i+2]; c++) {
                    s2[j++] = c;
                }
                 i += 3;  // Skip over the range (e.g., "a-d")
            }
    s2[j] = '\0';  // Null-terminate the output string
}

int main(void) {
char input[] = "a-d1-4q-z";
    char output[100];  // Ensure this is large enough for the output

    expand(input, output);
    printf("Expanded string: %s\n", output);
    
    return 0;
}
