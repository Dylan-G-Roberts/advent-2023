#include <stdio.h>

#define MAX_SIZE 1024


struct node {
    char node[4];
    char *left;
    char *right;
};


struct node makenode(char *node, char *left, char *right) {

}

int main() {

    char c;
    char lastchar = EOF;

    char directions[MAX_SIZE];

    int i;
    for (i = 0; (c=getchar()) != EOF; i++) {
        directions[i] = c;
        if (c == lastchar && lastchar == '\n') {
            directions[i] = '\0';
            break;
        }
        lastchar = c;
    }

//    for (int j = 0; directions[j] != '\n'; j++)
//        putchar(directions[j]);


    char node[4];
    char left[4];
    char right[4];

    char line[1000];
    struct node nodes[MAX_SIZE];

    int n = 0;
    while (fgets(line, sizeof(line), stdin) != NULL) {
        for (int j = 0; line[j] != '\0'; j++) {
            if (j < 3) {
                node[j] = line[j];
            } else if (j > 6 && j < 10) {
                left[j - 7] = line[j];
            } else if (j > 11 && j < 15) {
                right[j - 12] = line[j];
            }
        }
        node[3] = '\0';
        left[3] = '\0';
        right[3] = '\0';






        printf("node: %s, left: %s, right: %s \n",node, left, right);

        n++;
        }
    }