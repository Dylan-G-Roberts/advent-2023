#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LINE 100

#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)

int read_char_digit(char c) {
    if (c >= '1' && c <= '9') return c - '0';
    return -1;
}

int check_for_word(const char *str, const char *word, int word_value, int *number) {
    size_t word_length = strlen(word);
    if (strncmp(str, word, word_length) == 0) {
        *number = word_value;
        return word_length;
    }
    return 0;
}

int read_string_digit(const char *str, int *number) {
    int skip = 0;
    
    skip = skip || check_for_word(str, "zero", 0, number);
    skip = skip || check_for_word(str, "one", 1, number);
    skip = skip || check_for_word(str, "two", 2, number);
    skip = skip || check_for_word(str, "three", 3, number);
    skip = skip || check_for_word(str, "four", 4, number);
    skip = skip || check_for_word(str, "five", 5, number);
    skip = skip || check_for_word(str, "six", 6, number);
    skip = skip || check_for_word(str, "seven", 7, number);
    skip = skip || check_for_word(str, "eight", 8, number);
    skip = skip || check_for_word(str, "nine", 9, number);

    return skip;


}
int main() {
    TICK(TIME_A);
    char buffer[MAX_LINE];

    int sum, first, last, number, skip;
    first = -1;
    sum = last = number = skip = 0;
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        for (int i = 0; buffer[i] != '\0'; ++i) {
            number = read_char_digit(buffer[i]);

            if (number == -1) {
                skip = read_string_digit(&buffer[i], &number);
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