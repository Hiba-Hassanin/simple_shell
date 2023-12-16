#include "shell.h"

/**
 * main - entry point
 *
 * Return - always 0
*/

int main(void)
{
	char command[MAX_INPUT_LENGTH];

	while (1)
	{
		display_prompt();

		if (!read_command(command))
			break;

		execute_command(command);
	}

	return (0);
}
