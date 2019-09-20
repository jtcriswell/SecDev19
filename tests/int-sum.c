#include <stdio.h>

int main() {
    volatile int sum = 0;

    for (int i = 1; i <= 10; ++i) {
        sum += i;
    }

    printf("Sum of the first 10 positive integers: %d\n", sum);

    return 0;
}
