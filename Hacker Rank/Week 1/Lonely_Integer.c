#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i]; // XOR logic to cancel duplicates
    }
    
    printf("%d\n", result);
    return 0;
}
