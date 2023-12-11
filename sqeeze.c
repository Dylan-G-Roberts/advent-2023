#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LINE 1000

#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)

int getdigit(char c) {
    if (c >= '0' && c <= '9') return c - 48;
    return -1;
}

void updatestate(int *largestColor, int *i, int colorVal, int max, int skip) {
    *i += skip;
    if (colorVal > *largestColor) *largestColor = colorVal;
}

int ignorechar(char c) {
    return c == ' ' || c == ';' || c == ',';
}

int getstart(char buffer[MAX_LINE]) {
    // skip to the start of the data
    int start = 4;
    while (buffer[start] != ':') {start++;} 
    return start + 1;
}


int main() {
    TICK(TIME_A);
    char buffer[MAX_LINE];

    char skip = 's';
    int i, j;
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        for (i = j = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] != skip)
                buffer[j++] = buffer[i];
        }
        buffer[j] = '\0';
        for (i = 0; buffer[i] != '\0'; i++) {
            putchar(buffer[i]);
        } 
    }

    TOCK(TIME_A);

    return 0;
}