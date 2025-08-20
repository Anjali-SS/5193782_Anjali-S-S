#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int ranked[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ranked[i]);
    }
    
    int m;
    scanf("%d", &m);
    
    int player[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &player[i]);
    }
    
    // Step 1: compress leaderboard (remove duplicates)
    int unique[n], ucount = 0;
    unique[ucount++] = ranked[0];
    for (int i = 1; i < n; i++) {
        if (ranked[i] != ranked[i - 1]) {
            unique[ucount++] = ranked[i];
        }
    }
    
    // Step 2: process player scores
    int pos = ucount - 1; // start from lowest unique score
    for (int i = 0; i < m; i++) {
        int score = player[i];
        
        // Move up while player score >= leaderboard score
        while (pos >= 0 && score >= unique[pos]) {
            pos--;
        }
        
        // Rank is pos+2 (since pos stopped before correct place)
        printf("%d\n", pos + 2);
    }
    
    return 0;
}
