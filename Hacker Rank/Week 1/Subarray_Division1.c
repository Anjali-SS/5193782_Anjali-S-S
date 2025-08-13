#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Number of squares

    int s[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    int d, m;
    scanf("%d %d", &d, &m); // d = Ron's birth day, m = birth month

    int count = 0;

    // Check each segment of length m
    for (int i = 0; i <= n - m; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += s[i + j];
        }
        if (sum == d) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
