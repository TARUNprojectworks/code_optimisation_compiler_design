/* 10. Inter-Procedural Alias and Side-Effect Analysis */
#include <stdio.h>

void update(int *x, int *y) {
    *x = *x + 5;
    *y = *y + 10;
}

void test_alias(int *a, int *b) {
    update(a, b);
}

int main() {
    volatile int result = 0;
    int a, b;
    for (int iter = 0; iter < 100000000; iter++) {
        a = 0;
        b = 0;
        test_alias(&a, &b);
        result = a + b;
    }
    printf("%d\n", result);
    return 0;
}
