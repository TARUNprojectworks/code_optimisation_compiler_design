/* 4. SSA-Based Copy Propagation and Redundant phi-Elimination */
#include <stdio.h>

int main() {
    volatile int result = 0;
    for (int iter = 0; iter < 100000000; iter++) {
        int x = 10;
        int y = x;
        int z = y;
        int r;
        if (x > 5) {
            r = z;
        } else {
            r = z;
        }
        result = r;
    }
    printf("%d\n", result);
    return 0;
}
