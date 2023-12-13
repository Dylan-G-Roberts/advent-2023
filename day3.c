#include <stdio.h>
#include <ctype.h>

#define MAX_LINE 10 

int is_period(int c) {
    return c == 46;
}

int is_special(int c) {
    return (c >= 33 && c <= 47);
}

int is_digit(int c) {
    return c >= 48 && c <= 57;
}

int atoi(char s[], int i);

int main() 
{
    int c, lc, wc, sum;
    char grid[MAX_LINE][MAX_LINE + 1];
    wc = sum = lc = 0;

    while ((c = getchar()) != EOF) {
        grid[lc][wc++] = c;
        if (c == '\n') { 
            lc++; 
            wc = 0; 
        }
    }

    for (int row = 0; row < MAX_LINE; row++) {
        putchar('\n');
        for (int col = 0; col < MAX_LINE; col++) {
            int c = grid[row][col];
            putchar(c);
            if (is_special(c) && !is_period(c)) {
                if (col && is_digit(grid[row][col-1])) { // look left
                    int k = col - 1;
                    while (k >= 0 && is_digit(grid[row][k])) {
                        k--;
                    }
                    sum += atoi(grid[row], ++k);
                }
                if (col < MAX_LINE && is_digit(grid[row][col + 1])) { // look right
                    int k = col + 1;
                    sum += atoi(grid[row], k);
                }
                // look up
                if (row && is_digit(grid[row - 1][col])) {
                    // if I see a digit, build the full int and += sum
                    int k = col - 1;
                    char *focusRow = grid[row - 1]; 
                    while (k >= 0 && is_digit(focusRow[k])) {
                        k--;
                    }
                    sum += atoi(focusRow, ++k);
                } else {
                    if (row && col) { // up left
                        char *focusRow = grid[row - 1];
                        // look up left
                        int k = col - 1; 
                        while (k >= 0 && is_digit(focusRow[k])) {
                            k--;
                        }
                        sum += atoi(focusRow, ++k);
                    }

                    if (row && col + 1 < MAX_LINE) { // up right
                        char *focusRow = grid[row - 1];
                        if (is_digit(focusRow[col + 1])) {
                            int k = col + 1;
                            sum += atoi(focusRow, k);
                        }
                    }
                }

                // look down
                if (row + 1  < MAX_LINE && is_digit(grid[row + 1][col])) {
                    // if I look down and see a digit build the full int and += sum
                    int k = col - 1;
                    char *focusRow = grid[row + 1];
                    while (k >= 0 && is_digit(focusRow[k])) {
                        k--;
                    }
                    sum += atoi(focusRow, ++k);
                } else {
                    if (row + 1 < MAX_LINE && col) { // down left
                        // look down left
                        char *focusRow = grid[row + 1];
                        int k = col - 1; 
                        while (k >= 0 && is_digit(focusRow[k])) {
                            k--;
                        }
                        sum += atoi(focusRow, ++k);
                    }

                    if (row + 1 < MAX_LINE && col + 1 < MAX_LINE) { // down right
                        char *focusRow = grid[row + 1];
                        if (is_digit(focusRow[col + 1])) {
                            int k = col + 1;
                            sum += atoi(focusRow, k);
                        }
                    }
                }
            }
        }
    }

    printf("sum=%d", sum);
    return 0;
}


int atoi(char s[], int i) {
    int n;

    for (n = 0; is_digit(s[i]); i++)
        n = 10 * n + (s[i] - '0');

    return n;
}
