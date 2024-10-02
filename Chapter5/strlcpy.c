#include <stdio.h>


#define LENGTH 1000

void strlcpy(char *s, const char *f, int size) {
    if (size > 0) {
        while (--size > 0 && *f != '\0') {
            *s++ = *f++;
        }
        *s = '\0';
    }
}

int main(void) {
    char string[LENGTH] = "Hello World";
    char empty[LENGTH] = "";
    
    strlcpy(empty, string, LENGTH);
    printf("%s\n", empty);
    
    return 0;
}
