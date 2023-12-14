#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024


struct graph_node {
    char *label;
    char *left_label;
    int left_index;
    char *right_label;
    int right_index;
};

int compare_graph_nodes(const void *a, const void *b) {
    struct graph_node *node_a = (struct graph_node *) a;
    struct graph_node *node_b = (struct graph_node *) b;

    return strncmp(node_a->label, node_b->label, 3);
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



    struct node {
        char node[4];
        char *left;
        char *right;
    };
    struct node nodes[MAX_SIZE];
    /** 
    */
    struct map {
        char node[4];
        int index;
    };


    struct graph_node *graph = calloc(MAX_SIZE, sizeof(struct graph_node));


    int graph_size = 0;

    //qsort(graph, sizeof(struct graph), graph_size, compare_graph_nodes);
    char line[1000];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        char source[4], left[4], right[4];
        for (int j = 0; line[j] != '\0'; j++) {
            if (j < 3) {
                source[j] = line[j];
            } else if (j > 6 && j < 10) {
                left[j - 7] = line[j];
            } else if (j > 11 && j < 15) {
                right[j - 12] = line[j];
            }
        }
        source[3] = '\0';
        left[3] = '\0';
        right[3] = '\0';

        struct graph_node graph_key = { .label = source };
        struct graph_node *source_node = bsearch(&graph_key, graph, graph_size, sizeof(struct graph_node), compare_graph_nodes);

        if (!source_node) {
            struct graph_node *n = source_node = &graph[graph_size++];
            char *label = calloc(8, sizeof(char));
            strncpy(label, source, 4);

            n->label = label;
            n->left_index = -1;
            n->right_index = -1;
        }

        char *left_label = calloc(8, sizeof(char));
        char *right_label = calloc(8, sizeof(char));

        strncpy(left_label, left, 4);
        strncpy(right_label, right, 4);

        source_node->left_label = left_label;
        source_node->right_label = right_label;

        struct graph_node left_key = { .label = left };
        struct graph_node *left_node = bsearch(&left_key, graph, graph_size, sizeof(struct graph_node), compare_graph_nodes);

        if (!left_node) {
            struct graph_node *n = &graph[graph_size++];
            n->label = left_label;
            n->left_index = -1;
            n->right_index = -1;
        }

        struct graph_node right_key = { .label = right };
        struct graph_node *right_node = bsearch(&right_key, graph, graph_size, sizeof(struct graph_node), compare_graph_nodes);

        if (!right_node) {
            struct graph_node *n = &graph[graph_size++];
            n->label = right_label;
            n->left_index = -1;
            n->right_index = -1;
        }

        qsort(graph, graph_size, sizeof(struct graph_node), compare_graph_nodes);

        // valgrind

        printf("node: %s, left: %s, right: %s \n", source, left, right);
    }
}