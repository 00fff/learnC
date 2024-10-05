#include <stdio.h>

// Define the add function outside of main
int add(int a, int b) {
    return a + b;
}

int main(void) {
    int (*abb)(int, int); // Declare a function pointer
    abb = &add;           // Assign the address of the add function to the pointer

    int result = abb(5, 3); // Call the add function through the function pointer
    printf("The result is: %d\n", result); // Print the result

    return 0;
}
