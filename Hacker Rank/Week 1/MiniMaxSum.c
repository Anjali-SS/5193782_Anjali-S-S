#include <stdio.h>
#include <stdlib.h>

void miniMaxSum(int arr_count, int* arr) {
    long long totalSum = 0;
    int min = arr[0], max = arr[0];

    for (int i = 0; i < arr_count; i++) {
        totalSum += arr[i];
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    long long minSum = totalSum - max;
    long long maxSum = totalSum - min;

    // Add a space between %lld values
    printf("%lld %lld\n", minSum, maxSum);
}

int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    miniMaxSum(5, arr);
    return 0;
}
