#include "shell.h"

/**
 * display_prompt - Displays the shell prompt.
 */

void display_prompt(void)
{
	printf("$ ");
}

/**
 * execute_command - Executes the given command.
 * @command: The command to be executed.
 */

void execute_command(char *command)
{
	system(command);
}

/**
 * parse_command - Parses the command line and separates the command and arguments.
 * @input: The input command line.
 * @command: The buffer to store the command.
 * @arguments: The array to store the arguments.
 */

void parse_command(char *input, char *command, char *arguments[])
{
	char *token;
	int arg_index = 0;

	token = strtok(input, " \t\n");
	strcpy(command, token);

	while (token != NULL)
	{
		arguments[arg_index++] = token;
		token = strtok(NULL, " \t\n");
	}

	arguments[arg_index] = NULL;
}
