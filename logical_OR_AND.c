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
	int i = 0;

	while (subcommands[i] != NULL)
	{
		execute_single_command(subcommands[i]);
		i++;
	}
	for (i = 0; subcommands[i] != NULL; i++)
		free(subcommands[i]);
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
	int i = 0;

	while (subcommands[i] != NULL)
	{
		execute_single_command(subcommands[i]);
		i++;
	}
	for (i = 0; subcommands[i] != NULL; i++)
		free(subcommands[i]);
	free(subcommands);
}
