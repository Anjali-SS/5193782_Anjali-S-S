#include <stdio.h>
#include <string.h>

void timeConversion(char *s) {
    int hour, minute, second;
    char period[3]; // AM or PM

    // Extract hour, minute, second, and period from string
    sscanf(s, "%2d:%2d:%2d%s", &hour, &minute, &second, period);

    // Convert to 24-hour format
    if (strcmp(period, "AM") == 0) {
        if (hour == 12) hour = 0; // 12 AM is 00 hours
    } else { // PM
        if (hour != 12) hour += 12; // add 12 hours except for 12 PM
    }

    // Print in 24-hour format
    printf("%02d:%02d:%02d\n", hour, minute, second);
}

int main() {
    char s[11]; // Format: hh:mm:ssAM (10 chars + null)
    scanf("%s", s);

    timeConversion(s);
    return 0;
}
