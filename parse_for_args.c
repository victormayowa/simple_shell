#include "main.h"


/**
 * parse_command_for_arguments - Parse the given command for arguments.
 *
 * @command: The command to parse.
 *
 * Return: A null-terminated array of strings containing the arguments.
 */
char **parse_command_for_arguments(const char *command)
{
	char **arguments = malloc(sizeof(char *) * strlen(command));
	int i = 0;
	char *copy = strdup(command);
	char *token = strtok(copy, " \t\r\n");

	while (token != NULL)
	{
		if (token[0] != '>')
			arguments[i++] = strdup(token);
		token = strtok(NULL, " \t\r\n");
	}

	arguments[i] = NULL;

	free(copy);
	return (arguments);
}
