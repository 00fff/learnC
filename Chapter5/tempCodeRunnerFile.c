#include <stdio.h>

void reverse(char *s) {
    char temp[20];
    int i = 0;
    while (*s++ != '\0') {
        temp[i] = *s;
        printf("%d", temp[i]);
        i++;
    }
    temp[i] = '\0';       // Null-terminate the reversed string
    printf("%c", temp);
}

int main(void) {
    char string[20] = "hello world";
    reverse(string);
    return 0;
}