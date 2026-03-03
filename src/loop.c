/* 8. Loop Unrolling, Peeling, and Interchange */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test(int n, int m, int *a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            /* a[j][i] = i + j; using flat array: a[j*n + i] */
            a[j * n + i] = i + j;
        }
    }
}

int main() {
    int n = 200, m = 200;
    int *a = (int *)malloc(n * m * sizeof(int));
    volatile int result = 0;
    for (int iter = 0; iter < 10000; iter++) {
        test(n, m, a);
    }
    result = a[n * m - 1];
    printf("%d\n", result);
    free(a);
    return 0;
}
