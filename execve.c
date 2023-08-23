#include "simple.h"
void use_execve(char **array) {
    if (execve(array[0], array, NULL) == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
}
