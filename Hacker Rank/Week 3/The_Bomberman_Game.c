#include <stdio.h>
#include <string.h>

#define MAX 201

int R, C, N;
char grid[MAX][MAX];
char temp[MAX][MAX];

// function to copy one grid to another
void copyGrid(char src[MAX][MAX], char dest[MAX][MAX]) {
    for (int i = 0; i < R; i++)
        strcpy(dest[i], src[i]);
}

// detonate bombs
void detonate(char g[MAX][MAX], char out[MAX][MAX]) {
    // start with all bombs
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            out[i][j] = 'O';

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (g[i][j] == 'O') {
                out[i][j] = '.';
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < R && nj >= 0 && nj < C)
                        out[ni][nj] = '.';
                }
            }
        }
    }
    for (int i = 0; i < R; i++)
        out[i][C] = '\0'; // null terminate strings
}

int main() {
    scanf("%d %d %d", &R, &C, &N);
    for (int i = 0; i < R; i++)
        scanf("%s", grid[i]);

    if (N == 1) {
        // just print initial grid
        for (int i = 0; i < R; i++)
            printf("%s\n", grid[i]);
        return 0;
    }

    if (N % 2 == 0) {
        // even seconds -> full bombs
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) printf("O");
            printf("\n");
        }
        return 0;
    }

    char afterFirst[MAX][MAX], afterSecond[MAX][MAX];
    detonate(grid, afterFirst);
    detonate(afterFirst, afterSecond);

    if (N % 4 == 3) {
        for (int i = 0; i < R; i++) printf("%s\n", afterFirst[i]);
    } else {
        for (int i = 0; i < R; i++) printf("%s\n", afterSecond[i]);
    }

    return 0;
}
