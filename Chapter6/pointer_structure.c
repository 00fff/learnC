#include <stdio.h>
#define NKEYS 1000
int main(void) {
    int c;
    struct key 
    {
    char *word;  // This stores the keyword (e.g., "while")
    int count;   // This stores the count of how many times the keyword appears
    };
    struct key keytab[] = {
    { "auto", 0 },
    { "break", 0 },
    { "case", 0 },
    { "char", 0 },
    { "const", 0 },
};
    while (c = getchar()) {
        int i;
        while (i++ <= 5) {
            if (c == keytab[i].word) 
                continue;
            
        }
        return -1;
    }
    return 0;
}