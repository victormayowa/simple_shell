#include "main.h"

/**
 * execute_single_command - Executes a single command
 *
 * @command: The command to be executed
 *
 * Return: void
 */
int execute_single_command(const char *command)
{
	char **filenames = parse_command_for_filenames(command);
	char **arguments = parse_command_for_arguments(command);
	int exit_status = execute_external_command(arguments, filenames);

	free(filenames);
	free(arguments);
	return (exit_status);
}
