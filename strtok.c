#include "simple.h"

void tokenize(char *str, char *delim, char **array, int *count) {
    int i = 0;
    char **token;
    token = malloc(sizeof(char *) * BUF_SIZE);

    if (token == NULL) {
        exit(-1);
    }

    token[i] = strtok(str, delim);
    i++;

    while (1) {
        token[i] = strtok(NULL, delim);

        if (token[i] == NULL)
            break;

        i++;
    }

    for (int j = 0; j < i; j++) {
        array[j] = token[j];
    }
    
    *count = i;
    free(token);
}
