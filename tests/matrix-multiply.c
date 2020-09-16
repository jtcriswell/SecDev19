#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float randf(float low, float high) {
    long int r = random();
    return low + (float)((double)r * ((high - low) / (double)RAND_MAX));
}

void make_random_matrix(float* mat, size_t rows, size_t columns) {
    for (size_t i = 0; i < rows * columns; ++i) {
        mat[i] = randf(0.0f, 1000.0f);
    }
}

void multiply(float* restrict a, float* restrict b, float* restrict c, size_t rows, size_t inner, size_t columns) {
    memset(c, 0, sizeof(float) * rows * columns);

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            for (size_t k = 0; k < inner; ++k) {
                c[i * columns + j] += a[i * inner + k] * b[k * columns + j];
            }
        }
    }
}

void* xmalloc(size_t size) {
    void* allocation = malloc(size);
    if (allocation == NULL) {
        perror("Could not allocate memory for matrix");
        exit(1);
    }
    return allocation;
}

void print_matrix(float* mat, size_t rows, size_t columns) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            printf("%12.2f", mat[i * columns + j]);
        }
        if (i != rows - 1) {
            printf("\n");
        }
    }
}

int main() {
    const size_t rows = 10, inner = 8, columns = 12;

    float *a = xmalloc(sizeof(float) * rows * inner);
    float *b = xmalloc(sizeof(float) * inner * columns);
    float *c = xmalloc(sizeof(float) * rows * columns);

    make_random_matrix(a, rows, inner);
    make_random_matrix(b, inner, columns);

    printf("Left hand side:\n");
    print_matrix(a, rows, inner);
    printf("\n");

    printf("Right hand side:\n");
    print_matrix(b, inner, columns);
    printf("\n");

    multiply(a, b, c, rows, inner, columns);

    printf("Result:\n");
    print_matrix(c, rows, columns);
    printf("\n");

    return 0;
}
