#include <stdio.h>
#include <string.h>

void reverse(char *s) {
    char temp[20];
    char *p = temp;
    int len = strlen(s);
    
    s += len - 1;

    while (len--) {
        *p++ = *s--;
    }

    *p = '\0';
    printf("%s\n", temp);
}

int main(void) {
    char string[20] = "hello world";
    reverse(string);
    return 0;
}
