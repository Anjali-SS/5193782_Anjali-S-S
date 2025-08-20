#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* caesarCipher(char* s, int k) {
    int n = strlen(s);
    char* result = (char*)malloc((n + 1) * sizeof(char));

    k = k % 26; // normalize shift to within alphabet range

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (isalpha(c)) {
            if (islower(c)) {
                result[i] = ((c - 'a' + k) % 26) + 'a';
            } else {
                result[i] = ((c - 'A' + k) % 26) + 'A';
            }
        } else {
            result[i] = c; // leave symbols unchanged
        }
    }
    result[n] = '\0';
    return result;
}

int main() {
    int n, k;
    scanf("%d", &n);

    char s[1001]; // max length as per constraints
    scanf("%s", s);

    scanf("%d", &k);

    char* encrypted = caesarCipher(s, k);
    printf("%s\n", encrypted);

    free(encrypted);
    return 0;
}
