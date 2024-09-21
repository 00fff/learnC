# include <stdio.h>

int main(void)

{
int i, lim, c;
char s[100];
for( i=0; i<(lim-1); ++i )
{
    c = getchar();
    if( '\n' == c ) break;
    if( EOF  == c ) break;
    s[i] = c;
}
}
