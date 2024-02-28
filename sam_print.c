#include "shell.h"

void sam_print(const char *revert) {
    write(STDOUT_FILENO, revert, strlen(revert));
}
