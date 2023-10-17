#ifndef DOOR_SRUCT_H
#define DOOR_SRUCT_H

struct door {
    int id;
    int status;
};
void initialize_doors(struct door *doors);
void close_doors(struct door *doors);
void sort_doors(struct door *doors);
void output_doors(struct door *doors);

#endif
