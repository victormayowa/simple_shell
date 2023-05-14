#include "main.h"

/**
 * is_builtin_command - select buitlt in
 * @command: command to deal with
 * Return: 1 or 0 the buitlin to execute
 */

int is_builtin_command(const char *command)
{
	if (strncmp(command, "exit", 4) == 0)
		return (1);
	else if (strncmp(command, "@cd", 3) == 0)
		return (1);
	else if (strncmp(command, "@env", 4) == 0)
		return (1);
	else if (strncmp(command, "@setenv", 7) == 0)
		return (1);
	else if (strncmp(command, "@unsetenv", 9) == 0)
		return (1);
	else if (strncmp(command, "@alias", 6) == 0)
		return (1);
	return (0);
}

/**
 * handle_builtin_command - handles the selected builtin executiom
 * @command: command
 * Return: the comand
 */

void handle_builtin_command(const char *command)
{
	if (strncmp(command, "exit", 4) == 0)
		handle_exit_command(command);
	else if (strncmp(command, "@cd", 3) == 0)
		handle_cd_command(command);
	else if (strncmp(command, "@env", 4) == 0)
		handle_env_command(command);
	else if (strncmp(command, "@setenv", 7) == 0)
		handle_setenv_command(command);
	else if (strncmp(command, "@unsetenv", 9) == 0)
		handle_unsetenv_command(command);
	else if (strncmp(command, "@alias", 6) == 0)
		handle_alias_command(command);
}


/**
 * handle_exit_command - exit and exit status
 * @command: exit command
 * Return: exit or exit
 */

void handle_exit_command(const char *command)
{
	const char *exit_status_str = command + 4;
	int exit_status = atoi(exit_status_str);

	exit(exit_status);
}

/**
 * handle_cd_command - CD
 * @command: cd arg
 * Return: cd
 */

void handle_cd_command(const char *command)
{
	const char *directory = command + 3;

	if (chdir(directory) != 0)
		perror("cd");
}

/**
 * handle_alias_command - alias
 * @command: alias
 * Return: alias
 */

void handle_alias_command(const char *command)
{
	const char *alias = command + 6;
	const char *value = strchr(alias, ' ');

	if (value == NULL)
	{
		puts("Invalid format for alias command.");
		return;
	}
	value++;
}
