#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maxMin(int k, int arr[], int n) {
    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int min_unfairness = __INT_MAX__;
    for (int i = 0; i <= n - k; i++) {
        int diff = arr[i + k - 1] - arr[i];
        if (diff < min_unfairness) {
            min_unfairness = diff;
        }
    }
    return min_unfairness;
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxMin(k, arr, n);
    printf("%d\n", result);

    return 0;
}
