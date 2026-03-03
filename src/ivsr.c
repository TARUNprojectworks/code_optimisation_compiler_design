/* 6. Induction-Variable Strength Reduction and LFTR */
#include <stdio.h>
#include <stdlib.h>

void test(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i * 8;
    }
}

int main() {
    int n = 10000;
    int *arr = (int *)malloc(n * sizeof(int));
    volatile int result = 0;
    for (int iter = 0; iter < 100000; iter++) {
        test(arr, n);
    }
    result = arr[n - 1];
    printf("%d\n", result);
    free(arr);
    return 0;
}
