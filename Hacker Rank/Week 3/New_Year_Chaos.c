#include <stdio.h>

void minimumBribes(int q[], int n) {
    int bribes = 0;
    for (int i = 0; i < n; i++) {
        // If this person has moved more than 2 places ahead
        if (q[i] - (i + 1) > 2) {
            printf("Too chaotic\n");
            return;
        }

        // Check from max(0, q[i]-2) to current position i
        for (int j = (q[i] - 2 > 0 ? q[i] - 2 : 0); j < i; j++) {
            if (q[j] > q[i]) {
                bribes++;
            }
        }
    }
    printf("%d\n", bribes);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int q[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &q[i]);
        }

        minimumBribes(q, n);
    }

    return 0;
}
