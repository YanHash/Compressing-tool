#include "compression.c"


int main(int argc, char** argv) {
    if (argc == 2) {
        count_occurrence(argv[1]);
    }
    return 0;
}