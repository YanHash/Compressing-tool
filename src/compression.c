#include <stdio.h>
#include <stdlib.h>
#include "map.c"


Map* count_occurrence(char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Not able to open the file.");
        return NULL;
    }

    Map *map = malloc(sizeof(Map));
    if (map == NULL) {
        fclose(file);
        printf("Memory allocation failed.");
        return NULL;
    }

    *map = init();

    char charac;
    while ((charac = fgetc(file)) != EOF) {
        insert_incrementation(map, charac);
    }
    fclose(file);

    for (int i = 0; i < map_length(map); i++) {
        char key = get_keys(map)[i];
        printf("%c : %d\n", key, get_value(map, key));
    }

    return map;
}
