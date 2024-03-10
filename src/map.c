#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 128 // total of ascii characters

typedef struct {
    int _size;
    char _keys[MAX_SIZE];
    int _values[MAX_SIZE];
} Map;

Map init() {
    Map map = {._size = 0};
    return map;
}

int map_length(Map* map) {
    if (map != NULL) {
        return map->_size;
    } else {
        return 0;
    }
}

int get_value(Map* map, char key) {
    if (map_length(map) > 0) {
        for (int i = 0; i < map->_size; i++) {
            if (map->_keys[i] == key) {
                return map->_values[i];
            }
        }
    }
    return -1;
}

int insert_value(Map* map, char key, int value) {
    if (map_length(map) < MAX_SIZE) {
        for (int i = 0; i < map->_size; i++) {
            if (map->_keys[i] == key) {
                map->_values[i] = value;
                return 0;
            }
        }
        map->_keys[map->_size] = key;
        map->_values[map->_size] = value;
        map->_size++;
        return 0;
    }
    return -1;
}

int insert_incrementation(Map* map, char key) {
    return insert_value(map, key, get_value(map, key) + 1);
}

char* get_keys(Map* map) {
    char* keys = malloc(map->_size * sizeof(char));
    if (keys == NULL) {
        return NULL;
    }
    for (int i = 0; i < map->_size; i++) {
        keys[i] = map->_keys[i];
    }
    return keys;
}

int increment_value(Map* map, char key) {
    for (int i = 0; i < map->_size; i++) {
        if (map->_keys[i] == key) {
            map->_values[i]++;
            return 0;
        }
    }
    return -1;
}