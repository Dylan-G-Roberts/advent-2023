#include <stdio.h>
#include <time.h>

#define MAX_LINE 100
#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)

typedef struct race {
    long time;
    long distance;
};

typedef struct boat {
    long speed;
    long time;
};

long calc_distance(struct boat b) {
    return b.time * b.speed;
}

struct boat makeboat(long speed, long time) {
    struct boat temp;
    temp.speed = speed;
    temp.time  = time;
    return temp;
}

unsigned long long calc_number_of_wins(struct race r) {
    unsigned long wins = 0;
    for (int milliseconds = 0; milliseconds <= r.time; milliseconds++) {
        if (calc_distance(makeboat(r.time - milliseconds, milliseconds)) > r.distance)
            wins++;
    }
    return wins;
}

int main() {
    TICK(TIME_A);
    long ans;

    struct race r;
    r.time = 41777096;
    r.distance = 249136211271011;
    for (int i = 0; i < 1; i++) {
        long wins = calc_number_of_wins(r);
        ans = wins;
        printf("Race %d: Time = %lu, Distance = %lu, Wins = %lu\n", i + 1, r.time, r.distance, wins);
    }
    printf("ans= %llu\n", ans);
    TOCK(TIME_A);
    return 0;
}