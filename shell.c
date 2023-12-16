#include "shell.h"

/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void)
{
	printf("#cisfun$ ");
}

/**
 * read_command - Reads a command from stdin.
 * @command: The buffer to store the command.
 *
 * Return: 1 on success, 0 on failure or end of file.
 */
int read_command(char *command)
{
	if (fgets(command, MAX_INPUT_LENGTH, stdin) == NULL)
		return 0;

	command[strcspn(command, "\n")] = '\0'; // Remove the trailing newline character

	return (1);
}

/**
 * execute_command - Executes the given command.
 * @command: The command to be executed.
 */
void execute_command(char *command)
{
	if (access(command, X_OK) == 0)
		system(command);
	else
		fprintf(stderr, "%s: command not found\n", command);
}
