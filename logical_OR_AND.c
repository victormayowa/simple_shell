#include "main.h"

/**
 * execute_command_with_logical_or - Executes a command
 * that contains a logical OR operator (||)
 *
 * @command: The command to be execute
 * Return: d
 */
int execute_command_with_logical_or(const char *command)
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
	return (0);
}

/**
 * execute_command_with_logical_and - Executes a command
 * that contains a logical AND operator (&&)
 *
 * @command: The command to be executed
 * Return: 0 if success
 */
int execute_command_with_logical_and(const char *command)
{
	char **subcommands = split_command_by_logical_operator(command, "&&");
	size_t i = 0;
	int k;
	size_t subcommands_length = 0;

	while (subcommands[subcommands_length] != NULL)
	{
		subcommands_length++;
	}
	for (i = 0; i < subcommands_length; i++)
	{
		execute_single_command(subcommands[i]);
		k = execute_single_command(subcommands[i]);
		if (i < (subcommands_length - 1) && k != 0)
			break;
	}
	for (i = 0; i < subcommands_length; i++)
		free(subcommands[i]);
	free(subcommands);
	return (0);
}
