#include "main.h"

/**
 * execute_command - Executes a given command after processing it
 *
 * @command: The command to be executed
 */
void execute_command(const char *command)
{
	if (is_comment(command))
	{
		return;
	}

	char *processed_command = remove_comments(command);

	if (is_logical_operator_present(processed_command))
	{
		handle_logical_operator(processed_command);
	}
	else
	{
		execute_single_command(processed_command);
	}

	free(processed_command);
}

/**
 * is_comment - Checks if a given command is a comment
 *
 * @command: The command to be checked
 *
 * Return: 1 if the command is a comment, 0 otherwise
 */
int is_comment(const char *command)
{
	return (command[0] == '#');
}

/**
 * remove_comments - Removes the comments from a given command
 *
 * @command: The command to be processed
 *
 * Return: The command string with comments removed
 */
char *remove_comments(char *command)
{
	char *comment_pos = strchr(command, '#');

	if (comment_pos != NULL)
	{
		*comment_pos = '\0';
	}
	return (command);
}
