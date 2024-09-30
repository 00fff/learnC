#include <stdio.h>
#include <string.h>

void reverse(char *s) {
    char temp[20];
    int len = strlen(s); 
    s += len - 1;
    int i = 0;
    while (len--) {
        temp[i++] = *s--;
    }
    temp[i] = '\0';        // Null-terminate the reversed string
    printf("%s\n", temp);  // Print the reversed string
    
}

int main(void) {
    char string[20] = "hello world";
    reverse(string);
    return 0;
}