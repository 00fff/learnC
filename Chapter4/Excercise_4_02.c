#include <stdio.h>
#include <string.h>
#include <math.h>
// Function prototype for atof
double my_atof(char s[]);

// Function to convert string to integer
int atoi(char s[]) {
    return (int) my_atof(s);
}

// Function to convert string to double, including scientific notation
double my_atof(char s[]) {
    int length = 0, i = 0;
    int j = 0;
    int result;
    char first[100];
    char last[100];

    length = strlen(s);
    while (s[i] != 'E' && s[i] != 'e'){
            first[i] = s[i];
            i++;
        }
        i++;
    while (s[i] != '\0') {
    last[j] = s[i];
    j++;
    i++;
}
    int first_int = atoi(first);
    int last_int = atoi(last);
    result = pow(first_int, last_int);
    printf("%d", result);
    printf("%s\n%s", first, last);
    return 0.0; // Placeholder return value
}

int main() {
    char string[20] = "123.45e-6";
    int result = atoi(string);
    // printf("%d\n", result); // Output the integer part
    return 0;
}
