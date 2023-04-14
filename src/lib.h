#ifndef LIB_H
#define LIB_H

typedef struct {
    char *name;
    int capacity;
    char *location;
    char *condition;
    int is_occupied;
} Classroom;

Classroom *read_classrooms(const char *filename, int *num_classrooms);

#endif
