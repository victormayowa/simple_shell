#include "main.h"

/**
 * execute_single_command - Executes a single command
 *
 * @command: The command to be executed
 *
 * Return: void
 */
void execute_single_command(const char *command)
{
	char **filenames = parse_command_for_filenames(command);
	char **arguments = parse_command_for_arguments(command);

	execute_external_command(arguments, filenames);
	free(filenames);

	free(arguments);
}
