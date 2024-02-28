#include "shell.h"

void execute_command(const char *command) {
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process
        execlp(command, command, (char *)NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        wait(NULL);
    }
    return; // Added semicolon here
}


#include "shell.h"

void execute_command(const char *command)
{
    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        sam_print("Error forking process.\n");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0)
    {
       char *args[128];
       int arg_count = 0;

       cahr *token = strtok((char*)command, " ");
       while (token !=NULL) {
        args[arg_count++] = token;
        token = strtok(NULL, " ");
       }
    args[arg_count] = NULL;

    execvp(args[0], args);

    sam_print("Error executing command.\n");
    exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }

}
