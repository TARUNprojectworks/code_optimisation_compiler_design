/* 3. Global Common Subexpression Elimination (GVN/CSE) */
#include <stdio.h>

__attribute__((noinline))
int test(int a, int b, int c) {
    volatile int x = (a * b) + c;
    volatile int y = (a * b) - c;
    volatile int z = (a * b) * c;
    return x + y + z;
}

int main() {
    volatile int result = 0;
    for (int iter = 0; iter < 100000000; iter++) {
        result = test(3, 7, 2);
    }
    printf("%d\n", result);
    return 0;
}
