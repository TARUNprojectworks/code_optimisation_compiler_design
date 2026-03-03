/* 9. SIMD Autovectorization and Superword-Level Parallelism (SLP) */
#include <stdio.h>
#include <stdlib.h>

void test(int *a, int *b, int *c, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = b[i] + c[i];
    }
}

int main() {
    int n = 10000;
    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));
    int *c = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        b[i] = i;
        c[i] = i * 2;
    }
    volatile int result = 0;
    for (int iter = 0; iter < 100000; iter++) {
        test(a, b, c, n);
    }
    result = a[n - 1];
    printf("%d\n", result);
    free(a); free(b); free(c);
    return 0;
}
