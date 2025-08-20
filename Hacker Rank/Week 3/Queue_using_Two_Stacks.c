#include <stdio.h>
#include <stdlib.h>

#define MAX 100000   // max number of queries/elements (safe upper bound)

// Two stacks
int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Push into stack1 (enqueue)
void push1(int x) {
    stack1[++top1] = x;
}

// Push into stack2
void push2(int x) {
    stack2[++top2] = x;
}

// Pop from stack1
int pop1() {
    if (top1 == -1) return -1;
    return stack1[top1--];
}

// Pop from stack2
int pop2() {
    if (top2 == -1) return -1;
    return stack2[top2--];
}

// Enqueue operation
void enqueue(int x) {
    push1(x);
}

// Move elements from stack1 to stack2 if stack2 is empty
void transfer() {
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }
}

// Dequeue operation
void dequeue() {
    transfer();
    pop2();
}

// Peek operation (front element)
void peek() {
    transfer();
    printf("%d\n", stack2[top2]);
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int type, x;
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &x);
            enqueue(x);
        } else if (type == 2) {
            dequeue();
        } else if (type == 3) {
            peek();
        }
    }
    return 0;
}
