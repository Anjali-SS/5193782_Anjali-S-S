#include <stdio.h>
#include <stdlib.h>

// Comparator for ascending order
int cmpAsc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Comparator for descending order
int cmpDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int q; // number of queries
    scanf("%d", &q);

    while (q--) {
        int n, k;
        scanf("%d %d", &n, &k);

        int A[n], B[n];

        // Read array A
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }

        // Read array B
        for (int i = 0; i < n; i++) {
            scanf("%d", &B[i]);
        }

        // Sort A in ascending order
        qsort(A, n, sizeof(int), cmpAsc);

        // Sort B in descending order
        qsort(B, n, sizeof(int), cmpDesc);

        int possible = 1;
        for (int i = 0; i < n; i++) {
            if (A[i] + B[i] < k) {
                possible = 0;
                break;
            }
        }

        if (possible)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
