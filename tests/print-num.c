#include <stdio.h>

int main() {
    volatile int x = 42;

    printf("The number is %d\n", x);

    return 0;
}
