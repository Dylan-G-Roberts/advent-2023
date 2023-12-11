#include <stdio.h>

#define MAX_LINE 140

int is_period(int c) {
    return c == 46;
}

int is_special(int c) {
    return (c >= 33 && c <= 47);
}

int is_digit(int c) {
    return c >= 48 && c <= 57;
}

// int buildint(char grid[][MAX_LINE], int i, int j) {

// void lookaround(char grid[][MAX_LINE], struct point p) {
//     int up = grid[i - 1][j];
//     int down = grid[i + 1][j];
//     int left = grid[i][j - 1];
//     int right = grid[i][j + 1];
    
//     return buildint(grid, i, j) + buildint(right, i, j) + probeint(up) + probeint(down)
// }

int main() 
{
    int c, lc, wc, sum;
    char grid[MAX_LINE][MAX_LINE];
    sum = lc = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {lc++; wc = 0; continue;}
        grid[lc][wc++] = c;
    }

    for (int i = 0; i < MAX_LINE; i++) {
        putchar('\n');
        for (int j = 0; j < MAX_LINE; j++) {
            int c = grid[i][j];
            putchar(c); 
        }
    }

    return 0;
}