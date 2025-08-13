#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1001];
    
    // Read the entire line including spaces
    fgets(s, sizeof(s), stdin);
    
    int letters[26] = {0}; // to track each letter
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) { // check if it's a letter
            char lower = tolower(s[i]); // convert to lowercase
            letters[lower - 'a'] = 1; // mark as found
        }
    }
    
    // Check if all letters are found
    int isPangram = 1;
    for (int i = 0; i < 26; i++) {
        if (letters[i] == 0) {
            isPangram = 0;
            break;
        }
    }
    
    if (isPangram) {
        printf("pangram\n");
    } else {
        printf("not pangram\n");
    }
    
    return 0;
}
