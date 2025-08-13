#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // number of elements in the array
    
    int count[100] = {0}; // counting array (since values are in range 0..99)
    
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        count[value]++; // increment count of this number
    }
    
    // Print the counting array
    for (int i = 0; i < 100; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");
    
    return 0;
}
