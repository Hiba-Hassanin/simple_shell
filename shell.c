#include "shell.h"

/**
 * execute_command - Execute the given command
 * @command: The command to be executed
 */
void execute_command(char *command)
{
	pid_t pid;
	char *args[2];

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		args[0] = command;
		args[1] = NULL;

		if (execvp(args[0], args) == -1)
			perror("execvp");

		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}
