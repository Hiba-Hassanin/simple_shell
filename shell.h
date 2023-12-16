#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 1024

void display_prompt();
void execute_command(char *command);
void parse_command(char *input, char *command, char *arguments[]);

#endif
