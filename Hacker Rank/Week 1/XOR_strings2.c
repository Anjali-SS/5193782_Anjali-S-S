#include <stdio.h>
#include <string.h>

// You only need to modify this function
void strings_xor(char* s, char* t) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        // The core XOR logic: if characters are the same, result is '0', otherwise '1'
        if (s[i] == t[i]) {
            printf("0");
        } else {
            printf("1");
        }
    }
}

int main() {
    char s[10001], t[10001];
    scanf("%s", s);
    scanf("%s", t);
    
    strings_xor(s, t);
    
    // It's crucial to print a single newline at the very end
    printf("\n");
    
    return 0;
}