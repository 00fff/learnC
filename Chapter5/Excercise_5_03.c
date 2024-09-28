/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char *s, char *t) {

    /* Copy t to the end of s */
    while ((*s++ = *t++) != '\0') {
        ;  // Empty loop body
    }
}
