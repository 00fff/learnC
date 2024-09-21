#include <stdio.h>

int main(void)
{
char lower(char c);
int c;
c=getchar();
 printf("%c\n", lower(c));  // Should print 'a'

return 0;
}

char lower(char c) {
    return (c >= 'A' && c <= 'Z') ? c+=32 : c;
}