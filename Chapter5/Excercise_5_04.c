#include <stdio.h>
#include <string.h>

int strend(char *s, char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    // If t is longer than s, t can't be at the end of s
    if (len_t > len_s) {
        return 0;
    }

    // Compare the end of s with t
    s += len_s - len_t;  // Move pointer s to the last part of s that should match t

    while (*s && *t) {
        if (*s++ != *t++) {
            return 0;  // If any character doesn't match, return 0
        }
    }

    return 1;  // If all characters match, return 1
}
