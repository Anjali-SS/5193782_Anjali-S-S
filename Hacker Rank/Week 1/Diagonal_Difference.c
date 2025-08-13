#include <stdio.h>
#include <stdlib.h> // for abs()

int main() {
    int n;
    scanf("%d", &n); // read size of matrix

    int leftDiagonalSum = 0;
    int rightDiagonalSum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            scanf("%d", &value); // read matrix element
            if (i == j) {
                leftDiagonalSum += value; // primary diagonal
            }
            if (i + j == n - 1) {
                rightDiagonalSum += value; // secondary diagonal
            }
        }
    }

    int difference = abs(leftDiagonalSum - rightDiagonalSum);
    printf("%d\n", difference);

    return 0;
}
