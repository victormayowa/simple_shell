#include "main.h"

/**
 * execute_command_with_logical_or - Executes a command
 * that contains a logical OR operator (||)
 *
 * @command: The command to be executed
 */
void execute_command_with_logical_or(const char *command)
{
	char **subcommands = split_command_by_logical_operator(command, "||");

	for (int i = 0; subcommands[i] != NULL; i++)
	{
		if (execute_single_command(subcommands[i]) == 0)
		{
			break;
		}
	}
	free(subcommands);
}

/**
 * execute_command_with_logical_and - Executes a command
 * that contains a logical AND operator (&&)
 *
 * @command: The command to be executed
 */
void execute_command_with_logical_and(const char *command)
{
	char **subcommands = split_command_by_logical_operator(command, "&&");

	for (int i = 0; subcommands[i] != NULL; i++)
	{
		if (execute_single_command(subcommands[i]) != 0)
		{
			break;
		}
	}
	free(subcommands);
}
