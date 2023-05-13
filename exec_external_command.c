#include "main.h"

/**
 * execute_external_command - Execute an external command with optional
 * output and error redirection.
 * @arguments: The arguments for the command to execute.
 * @filenames: The filenames for output and error redirection.
 *
 * This function forks a new process to execute an external command
 * with optional output and error redirection. If filenames[0] is not
 * NULL, the output of the command will be redirected to the file
 * with that name. If filenames[1] is not NULL, the error output of
 * the command will be redirected to the file with that name.
 */
void execute_external_command(char **arguments, char **filenames)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (filenames[0] != NULL)
		{
			freopen(filenames[0], "w", stdout);
		}
		if (filenames[1] != NULL)
		{
			freopen(filenames[1], "w", stderr);
		}
		execvp(arguments[0], arguments);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
