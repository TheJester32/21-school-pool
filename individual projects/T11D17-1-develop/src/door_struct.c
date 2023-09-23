#include "door_struct.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zeroDoors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        if (doors[i].status > 0) {
            doors[i].status = 0;
        }
    }
}

void sort_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT - 1; i++) {
        for (int j = 0; j < DOORS_COUNT - i - 1; j++) {
            if (doors[j].id > doors[j + 1].id) {
                struct door temp = doors[j];
                doors[j] = doors[j + 1];
                doors[j + 1] = temp;
            }
        }
    }
}

void print_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}