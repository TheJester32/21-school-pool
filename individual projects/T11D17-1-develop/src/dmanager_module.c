#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

void initialize_doors(struct door* doors);
void sort_doors(struct door* doors);
void print_doors(struct door* doors);
void zeroDoors(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort_doors(doors);
    zeroDoors(doors);
    print_doors(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
