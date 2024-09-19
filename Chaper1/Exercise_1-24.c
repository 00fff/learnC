#include <stdio.h>
#include <string.h>
#define MAX 1000
int main(void)
{
    int i, c;
    int open_bracket = 0;
    int open_paren = 0;
    int open_curly = 0;
    int open_double = 0;
    int double2 = 0;
    char string[MAX];
    while ((c = getchar()) != EOF) {
        string[i++] = c;
    }
    string[i] = '\0';  // Null-terminate the string
    for (int j = 0; j < strlen(string); j++) {
        c = string[j];
        if (c == '"' && !open_double) {
            double2++;
            open_double = 1;
        } else if (c == '"' && open_double) {
                double2--;
                open_double = 0;
        } else if (c == '(') {
            open_paren++;
        } else if (c == ')') {
            open_paren--;
        }
        else if (c == '{') {
            open_curly++;
        } else if (c == '}') {
            open_curly--;
        }
    }
    printf("you have %d open parentesis\nyou have %d open curly ", open_paren, open_curly);
    return 0;
}