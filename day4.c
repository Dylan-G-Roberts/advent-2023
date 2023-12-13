#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000

int calculate_points(int matches) {
    int sum = 0;
    for (int i = 1; i < matches; i++) {
        if (i == 1)
            sum = 1;
        sum = sum * 2;
    }

    return sum;
}


int main() {
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        char winning_chars[30];
        int numbers[100];
        int matches = 0, j = 4;

        while (line[j] != ':') {j++;} // skip to the start of the data
        j++;

        char *p = &line[++j];

        int i = 0, num = 0;
        while (*p != '|') {
            winning_chars[i] = *p++;
            i++;
            num++;
        }


        char *token = strtok(winning_chars, " ");

        int count = 0;
        while (token != NULL) {
            if (token[0] >= '0' && token[0] <= '9') { // Check if the token is a number
                numbers[count++] = atoi(token); // Convert token to integer and store it in the array
            }
            token = strtok(NULL, " "); // Get the next token
        }

        numbers[count] = '\00';

        printf("BLAH ");
        for (i = 0; numbers[i] != '\00'; i++) {
            printf("%d ", numbers[i]);
        }



        putchar('\n');
    }
}