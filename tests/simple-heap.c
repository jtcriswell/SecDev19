#include <stdio.h>
#include <stdlib.h>

int* make_num() {
    int* num = malloc(sizeof(int));
    if (num == NULL) {
        perror("Unable to allocate memory");
    }
    *num = 42;

    return num;
}

void destroy_num(int* num) {
    *num = 0;
    free(num);
}

int main() {
    int* num = make_num();
    printf("The number is %d\n", *num);
    *num = 42;
    printf("The number is now %d\n", *num);
    destroy_num(num);

    return 0;
}
