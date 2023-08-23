#include "simple.h"

void use_pid(pid_t child_pid) {
    int status;
    wait(&status);
}
