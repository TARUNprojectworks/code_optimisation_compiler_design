/* 5. Loop-Invariant Code Motion (LICM) and Partial Redundancy Elimination (PRE) */
#include <stdio.h>

int main() {
    volatile int final_result = 0;
    for (int outer = 0; outer < 10000000; outer++) {
        int a = 4, b = 3;
        int result = 0;
        for (int i = 0; i < 10; i++) {
            int t = a * b;
            result += t + i;
        }
        final_result = result;
    }
    printf("%d\n", final_result);
    return 0;
}
