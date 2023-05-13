#include "main.h"

/**
 * is_logical_operator_present - Checks if a logical operator (&& or ||)
 * is present in a given command
 *
 * @command: The command to be checked
 *
 * Return: 1 if the command contains a logical operator, 0 otherwise
 */
int is_logical_operator_present(const char *command)
{
	return (strstr(command, "||") != NULL || strstr(command, "&&") != NULL);
}

/**
 * handle_logical_operator - Executes a command that
 * contains a logical operator (&& or ||)
 *
 * @command: The command to be executed
 */
void handle_logical_operator(const char *command)
{
	if (command[0] == '|')
	{
		execute_command_with_logical_or(command);
	}
	else if (command[0] == '&')
	{
		execute_command_with_logical_and(command);
	}
}

/**
 * split_command_by_logical_operator - Splits a command string
 * into subcommands based on a given logical operator
 *
 * @cmd: The command to be split
 * @oprt: The logical operator to use as a delimiter
 *
 * Return: An array of subcommands
 */
char **split_command_by_logical_operator(const char *cmd, const char *oprt)
{
	char **subcommands = malloc(sizeof(char *) * strlen(cmd));
	int i = 0;
	char *copy = strdup(cmd);
	char *token = strtok(copy, oprt);

	while (token != NULL)
	{
		subcommands[i++] = strdup(token);
		token = strtok(NULL, oprt);
	}
	subcommands[i] = NULL;

	free(copy);
	return (subcommands);
}
