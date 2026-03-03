/* 2. Global Dead-Code Elimination (DCE) and Unreachable-Code Removal */
#include <stdio.h>

int square(int num) {
    return num * num;
}

int test(int x) {
    int y = x * 100;
    int z = x + 50;
    y = 20;
    return y;
}

int main() {
    volatile int result = 0;
    for (int iter = 0; iter < 100000000; iter++) {
        result = test(iter) + square(iter);
    }
    printf("%d\n", result);
    return 0;
}
