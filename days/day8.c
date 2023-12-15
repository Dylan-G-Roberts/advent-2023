#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000
#include <time.h>


#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)


struct graph_node {
    char *label;
    char *left_label;
    int left_index;
    char *right_label;
    int right_index;
};

int find_node(char *label, int index);

int make_graph_node(const struct graph_node *graph, int graph_size, char *label);

int add_node(struct graph_node *graph, int graph_size, const char *key, char *label);
struct graph_node walkleft(struct graph_node curr, struct graph_node* graph, int graph_size);
struct graph_node walkright(struct graph_node curr, struct graph_node* graph, int graph_size);

int compare_graph_nodes(const void *a, const void *b) {
    struct graph_node *node_a = (struct graph_node *) a;
    struct graph_node *node_b = (struct graph_node *) b;

    return strncmp(node_a->label, node_b->label, 3);
}





int main() {
    TICK(TIME_A);

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

    struct graph_node *graph = calloc(MAX_SIZE, sizeof(struct graph_node)); /* alloc memory for our graph, array of graph nodes */
    int graph_size = 0;
    char line[1000];
    while (fgets(line, sizeof(line), stdin) != NULL) { /* for each line of input, add data to graph) */
        char source[4], left[4], right[4]; /* create char arrays for the three input strings */

        /* crappy parser built by yours truly */
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
        /* end this abomination */

        struct graph_node graph_key = { .label = source }; /* steal source str and use to search graph for node */
        struct graph_node *source_node = bsearch(&graph_key, graph, graph_size, sizeof(struct graph_node), compare_graph_nodes); /* search for our matching node */

        if (!source_node) {     /* if we didn't find it, we need to make it */
            struct graph_node *n = source_node = &graph[graph_size++]; /* create pointer, sourcenode, and set = to the addr at graph[graph_size++] */
            char *label = calloc(4, sizeof(char)); /* alloc memory so our source str isn't overwritten */
            strncpy(label, source, 4);  /* cp source into label */

            n->label = label;
            n->left_index = -1;
            n->right_index = -1;
        }



        char *left_label = calloc(4, sizeof(char)); /* alloc mem for left and right labels */
        char *right_label = calloc(4, sizeof(char));

        strncpy(left_label, left, 4);  /* cp data over */
        strncpy(right_label, right, 4);

        source_node->left_label = left_label;
        source_node->right_label = right_label;

        /* Build right node and add to graph */
        graph_size = add_node(graph, graph_size, left, left_label);

        /* Build right node and add to graph */
        graph_size = add_node(graph, graph_size, right, right_label);

        /* valgrind tool look into */

    }


    /*
     *  Find AAA (first pos)
     *  Try to walk
     *  if node = -1
     *      bsearch to find
     *      mark location and cont.
     *  sum is num of steps
     */
    struct graph_node curr = graph[0];
    struct graph_node *search_result;
    int count = 0;
    int shouldBreak = 0;
    while (!shouldBreak && strcmp(curr.label, "ZZZ")) {
        for (i = 0; (c = directions[i]) != '\n'; i++, count++) {
            if (c == 'L')
                curr = walkleft(curr, graph, graph_size);
            else if (c == 'R')
                curr = walkright(curr, graph, graph_size);

            /* If we find ZZZ we have our ans */
            if (!strcmp(curr.label, "ZZZ")) {
                shouldBreak = 1;
                break;
            }
        }
    }

    printf("count:%d\n", ++count);
    TOCK(TIME_A);
}

int add_node(struct graph_node *graph, int graph_size, const char *key, char *label) {
    struct graph_node _key = { .label = key };
    struct graph_node *node = bsearch(&_key, graph, graph_size, sizeof(struct graph_node), compare_graph_nodes);

    if (!node)
        graph_size = make_graph_node(graph, graph_size, label);

    /* Keep graph sorted so bsearch works */
    qsort(graph, graph_size, sizeof(struct graph_node), compare_graph_nodes);
    return graph_size;
}

int make_graph_node(const struct graph_node *graph, int graph_size, char *label) {
    struct graph_node *n = &graph[graph_size++];
    n->label = label;
    n->left_index = -1;
    n->right_index = -1;
    return graph_size;
}

struct graph_node walkleft(struct graph_node curr, struct graph_node* graph, int graph_size) {
    struct graph_node *search_result;

    if (curr.left_index != -1)
        curr = graph[curr.left_index];
    else {
        search_result = (struct graph_node *)bsearch(&curr.left_label, graph, graph_size, sizeof(struct graph_node), compare_graph_nodes);
        if (search_result != NULL) {
            int index = (int)(search_result - graph);
            curr.left_index = index;
            curr = *search_result;
        }
    }

    return curr;
}

struct graph_node walkright(struct graph_node curr, struct graph_node* graph, int graph_size) {
    struct graph_node *search_result;

    if (curr.right_index != -1)
        curr = graph[curr.right_index];
    else {
        search_result = (struct graph_node *)bsearch(&curr.right_label, graph, graph_size, sizeof(struct graph_node), compare_graph_nodes);
        if (search_result != NULL) {
            int index = (int)(search_result - graph);
            curr.right_index = index;
            curr = *search_result;
        }
    }

    return curr;
}