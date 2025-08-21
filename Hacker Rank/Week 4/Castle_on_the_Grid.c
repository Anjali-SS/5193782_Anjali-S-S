#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */

int minimumMoves(int grid_count, char** grid, int startX, int startY, int goalX, int goalY) {
    int n = grid_count;

    // visited matrix, initialized to 0
    int visited[100][100];   // max constraint is 100x100
    memset(visited, -1, sizeof(visited));

    // queue arrays for BFS
    int qx[10000], qy[10000];
    int front = 0, rear = 0;

    // start point
    qx[rear] = startX;
    qy[rear] = startY;
    rear++;
    visited[startX][startY] = 0;

    // BFS
    while (front < rear) {
        int x = qx[front];
        int y = qy[front];
        front++;

        // reached goal
        if (x == goalX && y == goalY) {
            return visited[x][y];
        }

        // explore in 4 directions
        // move up
        for (int i = x - 1; i >= 0 && grid[i][y] != 'X'; i--) {
            if (visited[i][y] == -1) {
                visited[i][y] = visited[x][y] + 1;
                qx[rear] = i; qy[rear] = y; rear++;
            }
        }
        // move down
        for (int i = x + 1; i < n && grid[i][y] != 'X'; i++) {
            if (visited[i][y] == -1) {
                visited[i][y] = visited[x][y] + 1;
                qx[rear] = i; qy[rear] = y; rear++;
            }
        }
        // move left
        for (int j = y - 1; j >= 0 && grid[x][j] != 'X'; j--) {
            if (visited[x][j] == -1) {
                visited[x][j] = visited[x][y] + 1;
                qx[rear] = x; qy[rear] = j; rear++;
            }
        }
        // move right
        for (int j = y + 1; j < n && grid[x][j] != 'X'; j++) {
            if (visited[x][j] == -1) {
                visited[x][j] = visited[x][y] + 1;
                qx[rear] = x; qy[rear] = j; rear++;
            }
        }
    }

    return -1; // unreachable

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** grid = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* grid_item = readline();

        *(grid + i) = grid_item;
    }

    char** first_multiple_input = split_string(rtrim(readline()));

    int startX = parse_int(*(first_multiple_input + 0));

    int startY = parse_int(*(first_multiple_input + 1));

    int goalX = parse_int(*(first_multiple_input + 2));

    int goalY = parse_int(*(first_multiple_input + 3));

    int result = minimumMoves(n, grid, startX, startY, goalX, goalY);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
