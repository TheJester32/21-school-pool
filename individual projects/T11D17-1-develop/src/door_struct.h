#ifndef DOOR_STRUCT_H
#define DOOR_STRUCT_H

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

struct door {
    int id;
    int status;
};

void sort_doors(struct door* doors);
void print_doors(struct door* doors);
void zeroDoors(struct door* doors);

#endif