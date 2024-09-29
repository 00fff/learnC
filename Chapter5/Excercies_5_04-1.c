int strindex(char *s, char *t) {
    char *s_start = s;  // Save the start of s to calculate the index later

    // Loop through the main string 's'
    while (*s != '\0') {
        char *s_temp = s;  // Pointer to traverse the current position of 's'
        char *t_temp = t;  // Pointer to traverse 't'

        // Traverse both strings while they match
        while (*t_temp != '\0' && *s_temp == *t_temp) {
            s_temp++;
            t_temp++;
        }

        // If we reach the end of 't', it means 't' is found in 's'
        if (*t_temp == '\0')
            return s - s_start;  // Return index of the start of 't' in 's'

        s++;  // Move to the next character in 's'
    }

    return -1;  // Return -1 if no match is found
}
