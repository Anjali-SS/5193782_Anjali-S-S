#include <stdio.h>
#include <stdint.h>

unsigned int flippingBits(unsigned int n) {
    // XOR with 0xFFFFFFFF flips all 32 bits
    return n ^ 0xFFFFFFFF;
}

int main() {
    int q;
    scanf("%d", &q); // number of queries
    
    for (int i = 0; i < q; i++) {
        unsigned int n;
        scanf("%u", &n); // read unsigned integer
        printf("%u\n", flippingBits(n));
    }
    return 0;
}
