#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char *argv[]) {
    int num_classrooms;
    Classroom *classrooms;
    int i;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s input output\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    classrooms = read_classrooms(argv[1], &num_classrooms);
        // Записуємо дані про аудиторії у вихідний файл
     FILE *fp = fopen(argv[2], "w"); 
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < num_classrooms; i++) {
        if (classrooms[i].capacity > 150) {
            fprintf(fp, "Аудиторії що вам підходять:%s\n", classrooms[i].name);
        }
    }



    fprintf(fp, "%d\n", num_classrooms);

    for (i = 0; i < num_classrooms; i++) {
        fprintf(fp, "%s,%d,%s,%s,%d\n", classrooms[i].name, classrooms[i].capacity, classrooms[i].location, classrooms[i].condition, classrooms[i].is_occupied);
    }

    fclose(fp);

    // Звільняємо пам'ять, яку було виділено для зберігання даних про аудиторії
    for (i = 0; i < num_classrooms; i++) {
        free(classrooms[i].name);
        free(classrooms[i].location);
        free(classrooms[i].condition);
    }

    free(classrooms);

    return EXIT_SUCCESS;
}
