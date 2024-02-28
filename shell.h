#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void display_prompt(void);
void sam_print(const char *revert);
void read_command(char *comand, size_t size);
void execute_command(const char *command);
void input_control(char *command, size_t size)

#endif /*SHELL_H*/