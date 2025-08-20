#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int heap[MAX+1];  // 1-indexed heap
int size = 0;

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up for insert
void heapifyUp(int idx) {
    while (idx > 1 && heap[idx] < heap[idx/2]) {
        swap(&heap[idx], &heap[idx/2]);
        idx = idx / 2;
    }
}

// Heapify down for delete
void heapifyDown(int idx) {
    int smallest = idx;
    int left = 2 * idx;
    int right = 2 * idx + 1;

    if (left <= size && heap[left] < heap[smallest]) smallest = left;
    if (right <= size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert element
void insert(int val) {
    size++;
    heap[size] = val;
    heapifyUp(size);
}

// Delete element (guaranteed to exist)
void delete(int val) {
    int idx = -1;
    for (int i = 1; i <= size; i++) {
        if (heap[i] == val) {
            idx = i;
            break;
        }
    }
    if (idx == -1) return; // safety, though guaranteed exists

    heap[idx] = heap[size];
    size--;
    heapifyUp(idx);
    heapifyDown(idx);
}

// Get minimum element
int getMin() {
    if (size == 0) return -1;
    return heap[1];
}

int main() {
    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        int type, val;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &val);
            insert(val);
        } else if (type == 2) {
            scanf("%d", &val);
            delete(val);
        } else if (type == 3) {
            printf("%d\n", getMin());
        }
    }
    return 0;
}
