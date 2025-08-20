#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    // Allocate an array of lists
    int** arr = (int**)malloc(n * sizeof(int*));
    int* sizes = (int*)calloc(n, sizeof(int)); // current sizes of each list
    int* capacities = (int*)malloc(n * sizeof(int)); // capacity for each list

    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(1 * sizeof(int));
        capacities[i] = 1;
    }

    int lastAnswer = 0;

    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);

        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            // Append y to arr[idx]
            if (sizes[idx] == capacities[idx]) {
                capacities[idx] *= 2;
                arr[idx] = (int*)realloc(arr[idx], capacities[idx] * sizeof(int));
            }
            arr[idx][sizes[idx]++] = y;

        } else if (type == 2) {
            // Retrieve element and update lastAnswer
            int value = arr[idx][y % sizes[idx]];
            lastAnswer = value;
            printf("%d\n", lastAnswer);
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    free(sizes);
    free(capacities);

    return 0;
}
