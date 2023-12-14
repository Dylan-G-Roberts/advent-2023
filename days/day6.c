#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100

typedef struct race {
    int time;
    int distance;
};

typedef struct boat {
    int speed;
    int time;
};


int calc_distance(struct boat b) {
    return b.time * b.speed;
}

struct boat makeboat(int speed, int time) {
    struct boat temp;

    temp.speed = speed;
    temp.time  = time;
    return temp;
}

int calc_number_of_wins(struct race r) {
    int wins = 0;
    for (int milliseconds = 0; milliseconds <= r.time; milliseconds++) {
        if (calc_distance(makeboat(r.time - milliseconds, milliseconds)) > r.distance)
            wins++;
    }

    return wins;
}


int main() {
    char line[MAX_LINE];


    struct race races[4]; // Array of 4 race structs

    // Read and process the time line
    if (fgets(line, sizeof(line), stdin) != NULL) {
        int index = 0;
        char *token = strtok(line, " ");

        // Skip the first token ("Time:")
        token = strtok(NULL, " ");

        while (token != NULL && index < 4) {
            races[index].time = atoi(token);
            token = strtok(NULL, " ");
            index++;
        }
    }

    // Read and process the distance line
    if (fgets(line, sizeof(line), stdin) != NULL) {
        int index = 0;
        char *token = strtok(line, " ");

        // Skip the first token ("Distance:")
        token = strtok(NULL, " ");

        while (token != NULL && index < 4) {
            races[index].distance = atoi(token);
            token = strtok(NULL, " ");
            index++;
        }
    }

    // Print the races for verification
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        ans *= calc_number_of_wins(races[i]);
        printf("Race %d: Time = %d, Distance = %d\n", i + 1, races[i].time, races[i].distance);
    }
    printf("ans= %d", ans);

    return 0;
}