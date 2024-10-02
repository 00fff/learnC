#include <stdio.h>
int main(void) {
    int x = 10;
    int *p = &x;

    printf("p: %p\n", p);    // Prints the address of x
    printf("*p: %d\n", *p);  // Prints the value of x (dereferenced pointer)
    printf("&p: %p\n", &p);  // Prints the address of the pointer variable p

    return 0;
}