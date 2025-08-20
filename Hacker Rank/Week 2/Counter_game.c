#include <stdio.h>

// Function to check if n is power of 2
int isPowerOfTwo(unsigned long long n) {
    return (n && !(n & (n - 1)));
}

// Function to find the largest power of 2 less than n
unsigned long long largestPowerOfTwo(unsigned long long n) {
    unsigned long long p = 1;
    while (p << 1ULL <= n) {
        p <<= 1ULL;
    }
    return p;
}

char* counterGame(unsigned long long n) {
    int moves = 0;

    while (n > 1) {
        if (isPowerOfTwo(n)) {
            n >>= 1;  // divide by 2
        } else {
            n -= largestPowerOfTwo(n); // subtract largest power of 2
        }
        moves++;
    }

    return (moves % 2 == 1) ? "Louise" : "Richard";
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        unsigned long long n;
        scanf("%llu", &n);
        printf("%s\n", counterGame(n));
    }

    return 0;
}
