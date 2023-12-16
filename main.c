#include "shell.h"

#define MAX_LINE_LENGTH 1024

/**
 * interactive_mode - Runs the shell program in interactive mode.
 */

void interactive_mode(void)
{
	char input[MAX_INPUT_LENGTH];
	char command[MAX_INPUT_LENGTH];
	char *arguments[MAX_INPUT_LENGTH];

	while (1)
	{
		display_prompt();

		if (fgets(input, sizeof(input), stdin) == NULL)
			break;

		if (strcmp(input, "exit\n") == 0)
			break;

		parse_command(input, command, arguments);
		execute_command(command);
	}
}

/**
 * non_interactive_mode - Runs the shell program in non-interactive mode.
 */

void non_interactive_mode(void)
{
	char input[MAX_INPUT_LENGTH];
	char command[MAX_INPUT_LENGTH];
	char *arguments[MAX_INPUT_LENGTH];

	while (fgets(input, sizeof(input), stdin) != NULL)
	{
		input[strcspn(input, "\n")] = '\0';

		parse_command(input, command, arguments);
		execute_command(command);
	}
}

/**
 * main - Entry point of the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 *
 * Return: 0 on success.
 */

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		non_interactive_mode();
	}
	else
	{
		interactive_mode();
	}

	return (0);
}
