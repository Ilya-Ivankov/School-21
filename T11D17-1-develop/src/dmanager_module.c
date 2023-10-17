#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

int main() {
#ifdef Quest_1
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    close_doors(doors);
    sort_doors(doors);
    output_doors(doors);
#endif
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void close_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}

void sort_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        for (int j = 0; j < DOORS_COUNT - 1; j++) {
            if (doors[j].id > doors[j + 1].id) {
                int temp = doors[j].id;
                doors[j].id = doors[j + 1].id;
                doors[j + 1].id = temp;
            }
        }
    }
}

void output_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d", doors[i].id, doors[i].status);
        if (i != DOORS_COUNT - 1) {
            printf("\n");
        }
    }
}
