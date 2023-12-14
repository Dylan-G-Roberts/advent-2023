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

    int overLimit, colorVal, largestRed, largestGreen, largestBlue;
    int sum = 0;
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        overLimit = largestRed = largestGreen = largestBlue = 0;

        for (int i = getstart(buffer); buffer[i] != '\0'; i++) {
            if (ignorechar(buffer[i])) continue;

            if (buffer[i] == 'b') {
                updatestate(&largestBlue, &i, colorVal, 14, 3);
                continue; 
            }
            if (buffer[i] == 'r') {
                updatestate(&largestRed, &i, colorVal, 12, 2);
                continue; 
            } 
            if (buffer[i] == 'g') {
                updatestate(&largestGreen, &i, colorVal, 13, 4);
                continue;
            }

            int digit = getdigit(buffer[i]);
            if (digit != -1) {
                int first = digit;
                int second = getdigit(buffer[++i]);
                if (second != -1) colorVal = first * 10 + second;
                else colorVal = first;
            }
        }
        sum += largestRed*largestGreen*largestBlue;
    }
    printf("\n%d\n", sum);

    TOCK(TIME_A);

    return 0;
}