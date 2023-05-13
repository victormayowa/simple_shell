#include "main.h"

/**
 * parse_command_for_filenames - Parses command for filenames
 *
 * @command: The command to be parsed
 *
 * Return: An array of filenames
 */
char **parse_command_for_filenames(const char *command)
{
	char **filenames = malloc(sizeof(char *) * strlen(command));
	int i = 0;
	char *copy = strdup(command);
	char *token = strtok(copy, " \t\r\n");

	while (token != NULL)
	{
		if (token[0] == '>')
		{
			filenames[i++] = strdup(token + 1);
		}
		token = strtok(NULL, " \t\r\n");
	}
	filenames[i] = NULL;

	free(copy);
	return (filenames);
}
