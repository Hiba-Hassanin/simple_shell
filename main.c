#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("$ ");
		fgets(command, sizeof(command), stdin);
		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
			break;
		else if (strcmp(command, "env") == 0)
			system("env");
		else
			execute_command(command);
	}

	return (0);
}
