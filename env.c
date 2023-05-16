#include "main.h"

/**
 * handle_env_command - env handler
 * @command: env command
 * Return: env command
 */

void handle_env_command(const char *command)
{
	char **env = environ;

	(void)command;
	for (; *env != NULL; env++)
		_puts(*env);
}

/**
 * handle_setenv_command - sentenv handle
 * @command: setenv
 * Return: function
 */

void handle_setenv_command(const char *command)
{
	const char *variable = command + 7;
	const char *value = _strchr(variable, ' ');

	if (value == NULL)
	{
		_puts("Invalid format for setenv command.");
		return;
	}
	value++;
	if (setenv(variable, value, 1) != 0)
		perror("setenv");
}

/**
 * handle_unsetenv_command - unsetenv
 * @command: unsetenv argument
 * Return: function
 */

void handle_unsetenv_command(const char *command)
{
	const char *variable = command + 9;

	if (unsetenv(variable) != 0)
		perror("unsetenv");
}
