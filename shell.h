#ifndef SHELL_H
#define SHELL_H

#define MAX_INPUT_LENGTH 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void display_prompt(void);
int read_command(char *command);
void execute_command(char *command);

#endif
