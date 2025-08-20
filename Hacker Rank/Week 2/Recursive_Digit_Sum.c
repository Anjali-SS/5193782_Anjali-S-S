#include <stdio.h>
#include <string.h>

// Recursive function to calculate super digit
int superDigitHelper(long long num) {
    if (num < 10) return (int)num;  // base case

    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return superDigitHelper(sum);
}

int superDigit(char* n, int k) {
    long long sumN = 0;

    // Step 1: sum digits of string n
    for (int i = 0; n[i] != '\0'; i++) {
        sumN += (n[i] - '0');
    }

    // Step 2: multiply by k (effective first concatenation sum)
    long long initial = sumN * k;

    // Step 3: find super digit
    return superDigitHelper(initial);
}

int main() {
    char n[100001];  // n can be very large (up to 10^100000)
    int k;
    scanf("%s %d", n, &k);

    printf("%d\n", superDigit(n, k));
    return 0;
}
