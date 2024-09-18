#include <stdio.h>
#define MAXLINE 1000
#define N 20

int main() 
{
    int c, i = 0, j, current_length = 0;
    char input[MAXLINE];

    // Reading input until EOF and storing characters in the input array
    while ((c = getchar()) != EOF && i < MAXLINE - 1) {  // Ensure no overflow
       if (c == ' ' || current_length == N) {
        if (c != ' ')
            input[i] = c;
        input[i++] = '\n';
        if (current_length== N)
            current_length = 0;
       } else {
        input[i++] = c;
       current_length++;
       }
       

    }
    
    input[i] = '\0';  // Null-terminate the string
    
    // Printing the characters stored in input
    printf("%s", input);  // Removed extra space after %c

    return 0;
}
