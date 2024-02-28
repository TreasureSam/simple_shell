#include "shell.h"

void execute_command(const char *command)   {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // process the child

        // build entire path to the command
        char command_path[256];
        snprintf(command_path, sizeof(command_path), "/bin/%s", command);

        char *args[] = {command, NULL};
        execve(command_path, args, NULL);

        perror("execve");
        exit(EXIT_FAILURE);
    } else  {
        // guardian process
        wait(NULL);
    }
}