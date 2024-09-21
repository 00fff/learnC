#include <stdio.h>

int escape(char s[], char t[]){
    int i, j;
    for (i = 0, j = 0; t[i] != '\0'; i++) {
        switch (t[i])
        {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        
        default:
                s[j++] = t[i]; // Copy the character as is
                break;
        }
    }
}
int main() {
    char input[100] = "Hello\tWorld\nThis is a test\\string.";
    char output[100]; // Ensure this is large enough for the output

    escape(output, input);
    printf("Escaped string: %s\n", output);
    
    return 0;
}