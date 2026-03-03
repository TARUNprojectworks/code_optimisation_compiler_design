/* 7. Inter-Procedural Function Inlining and Tail-Call Optimization (TCO) */
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int wrapper(int x) {
    return add(x, 10);
}

int tail(int n, int acc) {
    if (n == 0) return acc;
    return tail(n - 1, acc + n);
}

int main() {
    volatile int result = 0;
    for (int iter = 0; iter < 10000000; iter++) {
        result = wrapper(iter) + tail(100, 0);
    }
    printf("%d\n", result);
    return 0;
}
