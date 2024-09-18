# include <stdio.h>
# define MAXLINE 1000
int main()
{
    int c, i = 0, space = 0;
    char words[MAXLINE];
    while ((c=getchar()) != EOF) {
        if (c == ' ' && space <= 4) {
            space++;
        } else {
            while (space > 0) {
                 if (space >= 4) {
                    // If we have 4 or more spaces, use a tab
                    words[i++] = '\t';
                    space -= 4;
                } else {
                    // If fewer than 4 spaces, use individual spaces
                    words[i++] = ' ';
                    space--;
                }
            }
            // Add the non-space character to the array
            words[i++] = c;
        }
    }
    words[i] = '\0';
        printf("%s", words);
    return 0;
}