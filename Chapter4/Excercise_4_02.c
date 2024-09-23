#include <stdio.h>
#include <string.h>
#include <math.h>

// Custom atoi implementation to convert string to integer
int my_atoi(char s[]) {
    int num = 0, i = 0;
    int sign = 1;
    
    // Handle negative numbers
    if (s[0] == '-') {
        sign = -1;
        i++;
    }
    
    // Iterate over the string to form the integer
    while (s[i] != '\0') {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    
    return sign * num;
}

// Custom my_atof function to handle strings in scientific notation
double my_atof(char s[]) {
    int i = 0, j = 0;
    char first[100];  // String for the base part
    char last[100];   // String for the exponent part
    
    // Extract the base part until 'e' or 'E'
    while (s[i] != 'E' && s[i] != 'e' && s[i] != '\0') {
        first[i] = s[i];
        i++;
    }
    first[i] = '\0';  // Null-terminate the base string

    // Skip 'e' or 'E'
    i++;
    
    // Extract the exponent part
    while (s[i] != '\0') {
        last[j] = s[i];
        j++;
        i++;
    }
    last[j] = '\0';  // Null-terminate the exponent string

    // Convert the base and exponent to numbers
    double base = atof(first);    // Convert the base part to double
    int exponent = my_atoi(last); // Convert the exponent part to integer using custom atoi

    // Perform the scientific notation calculation: base * 10^exponent
    return base * pow(10, exponent);
}

int main() {
    char string[20] = "123.45e-6";
    double result = my_atof(string);  // Convert string to double with scientific notation
    printf("%lf\n", result);          // Output the result
    return 0;
}
