/* 1. Inter-Procedural Constant Propagation (IPA-CP) and Folding */
#include <stdio.h>

static int __attribute__((noinline)) multiply(int a, int b) {
    return a * b;
}

int main() {
    volatile int result = 0;
    for (int iter = 0; iter < 100000000; iter++) {
        result = multiply(5, 5) + multiply(5, 10);
    }
    printf("%d\n", result);
    return 0;
}
