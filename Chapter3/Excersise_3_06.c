#include <stdio.h>
#include <string.h>

void convert(int n, char string[], int base, int width) {
    int i = 0, c, remainder, q;
    int j = 0;
    char temp;
    char digits[] = "0123456789ABCDEF";  // Characters for digits in base up to 16
    do {
        remainder = n % base;
        string[i++] = digits[remainder];
         n /= base;  // Reduce the number for next iteration
    } while (n > 0);
     string[i] = '\0';  
     i--;
    while (j < i) {
        temp = string[j];
        string[j] = string[i];
        string[i] = temp;
        j++;
        i--;
    }
    int str_len = strlen(string);
    if (str_len < width) {
        int padding = width - str_len;
        for (i = str_len; i >= 0; i--) {
            string[i + padding] = string[i];  // Shift characters to the right
        }
        for (i=0; i < padding; i++) {
            string[i] = ' ';
        }
    }
    printf("%s", string);   
}
int main(void) 
{
    int n = 32, base = 16, width = 10;
    char string[10];
    convert(n, string, base, width);

    return 0;
}