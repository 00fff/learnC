#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void remove_comments(char str[], char no_com_str[]) {
    int c, i, j = 0, s = 0;  // `j` is for keeping track of the position in no_com_str
    int in_single_line_comment = 0;
    int in_multi_line_comment = 0;
    for (i=0; i < strlen(str); i++) {
        c = str[i];
        if (c == '/' && str[i + 1] == '/' && !in_multi_line_comment) { 
            in_single_line_comment = 1;
            i++;  // Skip the next '/'
        } else if (c == '/' && str[i + 1] == '*' && !in_single_line_comment)
        {
            in_multi_line_comment = 1;
            i+=2;  
        } else if (c == '\n' && in_single_line_comment) {
            in_single_line_comment = 0;
            no_com_str[j++] = str[i];  // Add the newline to keep the structure
        } else if (c == '*' && str[i + 1] == '/' && in_multi_line_comment) {
            in_multi_line_comment = 0;
            i += 2;  // 
        }  else if (!in_single_line_comment && !in_multi_line_comment) {
            no_com_str[j++] = str[i];
        }
    }
        no_com_str[i] = '\0'; 
        }
       
    
    


int main(void) 
{
    int i = 0, c;
    char input[MAXLINE];
    char striped[MAXLINE];  // This will hold the result with comments removed
    
    // Read input until EOF, storing characters in the input array
    while ((c = getchar()) != EOF && i < MAXLINE - 1) {  // Avoid buffer overflow
        input[i++] = c; 
    }

    input[i] = '\0';  // Null-terminate the input string

    // Now remove comments from the input and store it in the striped array
    remove_comments(input, striped);

    // Output the striped version without comments
    printf("Program without comments:\n%s", striped);

    return 0;
}
