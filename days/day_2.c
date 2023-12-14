#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LINE 1000

#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)

int read_char_digit(char c) {
    if (c >= '0' && c <= '9') return c - 48;
    return -1;
}

void update_state(int *overLimit, int *i, int val, int max, int skip) {
    *i += skip;
    if (val > max)
        *overLimit = 1;
}

int main() {
    TICK(TIME_A);
    char buffer[MAX_LINE];

    int ones, tens, j, val;
    int overLimit, sum, line = 0;
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        j = 4;
        overLimit = 0;
        line++;
        int numRed, numGreen, numBlue = 0;
        while (buffer[j] != ':') {j++;} // skip to the start of the data


        for (int i = j + 1; buffer[i] != '\0'; i++) {
            if (buffer[i] == ' ' || buffer[i] == ';' || buffer[i] == ',' ) continue;
            if (buffer[i] == 'b') {
                update_state(&overLimit, &i, val, 14, 3);
                continue; 
            }
            if (buffer[i] == 'r') {
                update_state(&overLimit, &i, val, 12, 2);
                continue; 
            } 
            if (buffer[i] == 'g') {
                update_state(&overLimit, &i, val, 13, 4);
                continue;
            }



            int digit = read_char_digit(buffer[i]);
            if (digit != -1) {
                int first = digit;
                int second = read_char_digit(buffer[++i]);
                if (second != -1) val = first * 10 + second;
                else val = first;
                printf("%d\n", val);
            }
        }

        if (overLimit == 0) sum += line;
    }
    printf("\n%d\n", sum);

    TOCK(TIME_A);

    return 0;
}