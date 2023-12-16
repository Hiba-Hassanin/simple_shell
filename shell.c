#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char command[MAX_COMMAND_LENGTH];

	if (argc == 1)
	{
		while (1)
		{
			printf("($) ");
			fgets(command, sizeof(command), stdin);
			command[strcspn(command, "\n")] = '\0';
			if (strcmp(command, "exit") == 0)
				break;
			else if (strcmp(command, "env") == 0)
				system("env");
			else
				execute_command(command);
		}
	}
	else if (argc == 2)
	{
		FILE *file = fopen(argv[1], "r");
		char line[MAX_COMMAND_LENGTH];

		if (!file)
		{
			perror("fopen");
			exit(EXIT_FAILURE);
		}

		while (fgets(line, sizeof(line), file))
		{
			line[strcspn(line, "\n")] = '\0';
			execute_command(line);
		}

		fclose(file);
	}
	else
	{
		fprintf(stderr, "Usage: %s [script_file]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	return (0);
}

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
