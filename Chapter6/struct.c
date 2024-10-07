#include <stdio.h>

int main(void) {
    struct rectangle {
        int angle_one;
        int angle_two;

    };
    struct rectangle rect;
    rect.angle_one = 20;
    printf("%d",rect.angle_one);
    return 0;
}