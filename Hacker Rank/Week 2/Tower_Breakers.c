#include <stdio.h>
#include <stdlib.h>

int towerBreakers(int n, int m) {
    if (m == 1) {
        return 2; // If towers are height 1, Player 1 cannot move, Player 2 wins
    }
    if (n % 2 == 0) {
        return 2; // If number of towers is even, Player 2 can always mirror Player 1
    }
    return 1; // Otherwise, Player 1 wins
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int result = towerBreakers(n, m);
        printf("%d\n", result);
    }
    return 0;
}
