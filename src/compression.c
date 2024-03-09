#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char character;
    int occuring;
} occurence;


occurence* count_occurnce(char* filename) {
    FILE *file;
    if (file == NULL) {
        printf("Not able to open the file.");
        return -1;
    }else {
        file = fopen(filename, "r");
        char c;
        while ((c = fgetc(file)) == EOF) {
            
        }
    }
}