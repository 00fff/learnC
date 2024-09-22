/*Write  a function "strrindex(s,t)" that returns the right most index of the letter T*/
#include <stdio.h>
#include <string.h>
int strrindex(char s[], char t[]) {
    int i;
    int size = strlen(s);
    int location = -1;
    for (i = 0; i < size; i++) {
        if (s[i] == t[0]) 
            location = i;
    }
    return location;
}

int main(void) {
    char string[20] = "test string with t";
    char t[] = "t";  // Initialize t as a string
    int index = strrindex(string, t);
    
    // Output the result
    printf("Rightmost occurrence of 't' is at index: %d\n", index);

    return 0;
}