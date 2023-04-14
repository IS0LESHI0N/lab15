#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

Classroom *read_classrooms(const char *filename, int *num_classrooms) {
    FILE *fp;
    char line[256];
    Classroom *classrooms;
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Першим рядком в файлі має бути кількість аудиторій
    fgets(line, sizeof(line), fp);
    *num_classrooms = atoi(line);
    classrooms = malloc((size_t)*num_classrooms * sizeof(Classroom));

    while (fgets(line, sizeof(line), fp)) {
        char *name = strtok(line, ",");
        int capacity = atoi(strtok(NULL, ","));
        char *location = strtok(NULL, ",");
        char *condition = strtok(NULL, ",");
        int is_occupied = atoi(strtok(NULL, ","));

        classrooms[i].name = strdup(name);
        classrooms[i].capacity = capacity;
        classrooms[i].location = strdup(location);
        classrooms[i].condition = strdup(condition);
        classrooms[i].is_occupied = is_occupied;

        i++;
    }

    fclose(fp);

    return classrooms;
}
