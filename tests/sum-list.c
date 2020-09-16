#include <stdio.h>
#include <stdlib.h>

float randf(float low, float high) {
    long int r = random();
    return low + (float)((double)r * ((high - low) / (double)RAND_MAX));
}

void make_random_list(float* mat, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        mat[i] = randf(0.0f, 1000.0f);
    }
}

float sum_list(float* list, size_t len) {
    float sum = 0.0f;

    for (size_t i = 0; i < len; ++i) {
        sum += list[i];
    }

    return sum;
}

void* xmalloc(size_t size) {
    void* allocation = malloc(size);
    if (allocation == NULL) {
        perror("Could not allocate memory for list");
        exit(1);
    }
    return allocation;
}

void print_list(float* list, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%8.2f", list[i]);
    }
    printf("\n");
}

int main() {
    const size_t len = 16;

    float *list = xmalloc(sizeof(float) * len);

    make_random_list(list, len);

    printf("List: ");
    print_list(list, len);

    float sum = sum_list(list, len);

    printf("Sum: %f\n", sum);

    return 0;
}
