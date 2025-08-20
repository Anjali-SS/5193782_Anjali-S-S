#include <stdio.h>
#include <math.h>

long sumXor(long n) {
    if (n == 0) return 1; // special case
    
    int zeroBits = 0;
    while (n > 0) {
        if ((n & 1) == 0) {
            zeroBits++; // count zeros
        }
        n >>= 1;
    }
    
    return 1L << zeroBits; // 2^zeroBits
}

int main() {
    long n;
    scanf("%ld", &n);
    printf("%ld\n", sumXor(n));
    return 0;
}
