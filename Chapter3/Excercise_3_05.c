#include <stdio.h>
#include <string.h>

void convert(int n, char string[], int base) {
    int i = 0, c, remainder;
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
    
    printf("%s", string);   
}
int main(void) 
{
    int n = 32, base = 16;
    char string[100];
    convert(n, string, base);

    return 0;
}