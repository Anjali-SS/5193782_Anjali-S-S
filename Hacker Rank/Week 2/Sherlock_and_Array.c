#include <stdio.h>
#include <stdlib.h>

const char* balancedSums(int arr[], int n) {
    long long total = 0, leftSum = 0;

    for (int i = 0; i < n; i++) {
        total += arr[i];
    }

    for (int i = 0; i < n; i++) {
        long long rightSum = total - leftSum - arr[i];
        if (leftSum == rightSum) {
            return "YES";
        }
        leftSum += arr[i];
    }
    return "NO";
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        printf("%s\n", balancedSums(arr, n));
    }
    return 0;
}
