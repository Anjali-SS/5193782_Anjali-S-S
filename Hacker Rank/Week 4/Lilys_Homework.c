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

#include <stdio.h>
#include <stdlib.h>

// Define struct globally
typedef struct {
    int val, idx;
} Pair;

// Comparator for ascending order
int cmpAsc(const void *a, const void *b) {
    return ((Pair*)a)->val - ((Pair*)b)->val;
}

// Comparator for descending order
int cmpDesc(const void *a, const void *b) {
    return ((Pair*)b)->val - ((Pair*)a)->val;
}

// Helper to count swaps
int countSwaps(Pair* pairs, int arr_count) {
    int* visited = calloc(arr_count, sizeof(int));
    int swaps = 0;

    for (int i = 0; i < arr_count; i++) {
        if (visited[i] || pairs[i].idx == i) continue;

        int cycle_size = 0, j = i;
        while (!visited[j]) {
            visited[j] = 1;
            j = pairs[j].idx;
            cycle_size++;
        }
        if (cycle_size > 1) swaps += (cycle_size - 1);
    }

    free(visited);
    return swaps;
}

// Main function
int lilysHomework(int arr_count, int* arr) {
    Pair* pairs = malloc(arr_count * sizeof(Pair));
    for (int i = 0; i < arr_count; i++) {
        pairs[i].val = arr[i];
        pairs[i].idx = i;
    }

    // Sort ascending
    qsort(pairs, arr_count, sizeof(Pair), cmpAsc);
    int asc_swaps = countSwaps(pairs, arr_count);

    // Reset pairs
    for (int i = 0; i < arr_count; i++) {
        pairs[i].val = arr[i];
        pairs[i].idx = i;
    }

    // Sort descending
    qsort(pairs, arr_count, sizeof(Pair), cmpDesc);
    int desc_swaps = countSwaps(pairs, arr_count);

    free(pairs);
    return asc_swaps < desc_swaps ? asc_swaps : desc_swaps;
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }

    int result = lilysHomework(n, arr);

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
