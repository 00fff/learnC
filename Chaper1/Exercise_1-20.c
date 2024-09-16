# include <stdio.h>
# define MAXLINE 1000
int main()
{
    int c, i, tab = 4, count;
    char words[MAXLINE];
    while ((c=getchar()) != EOF) {
        if (c == '\t') {
            for (count = 0; count < tab; count++) {
                words[i] = ' ';
                i++;  // Increment index correctly
            }
        }
        words[i] = c;
        i++;
            
    }
printf("%s", words);  // Use %s to print the entire string at once

    return 0;
}