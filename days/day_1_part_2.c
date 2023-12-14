#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LINE 100

#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)

int char_to_int(char c) {
    return c - 48;
}

int check_for_word(const char *str, const char *word, int word_value, int *number) {
    size_t word_length = strlen(word);
    if (strncmp(str, word, word_length) == 0) {
        *number = word_value;
        return word_length - 1;
    }
    return 0;
}

int main() {
    TICK(TIME_A);
    char buffer[MAX_LINE];

    int sum = 0, first = -1, last = 0;
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        for (int i = 0; buffer[i] != '\0'; ++i) {
            int number = word_to_int(buffer[i]);
            int skip = 0;

            if (number == -1) {
                skip = skip || check_for_word(&buffer[i], "zero", 0, &number);
                skip = skip || check_for_word(&buffer[i], "one", 1, &number);
                skip = skip || check_for_word(&buffer[i], "two", 2, &number);
                skip = skip || check_for_word(&buffer[i], "three", 3, &number);
                skip = skip || check_for_word(&buffer[i], "four", 4, &number);
                skip = skip || check_for_word(&buffer[i], "five", 5, &number);
                skip = skip || check_for_word(&buffer[i], "six", 6, &number);
                skip = skip || check_for_word(&buffer[i], "seven", 7, &number);
                skip = skip || check_for_word(&buffer[i], "eight", 8, &number);
                skip = skip || check_for_word(&buffer[i], "nine", 9, &number);
                i += skip;
            }

            if (number != -1) {
                if (first == -1) first = number;
                last = number;
            }
        }
        if (first != -1) {
            sum += first * 10 + last;
            first = -1;
        }
    }

    printf("%d\n", sum);
    TOCK(TIME_A);

    return 0;
}