#include "main.h"

/**
 * main - the main executing funtion
 * Return: interactive or nonn interactive
 */

int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		run_interactive_shell();
	}
	else
	{
		char *cmd = NULL;

		run_non_interactive_shell(cmd);
	}
	return (0);
}

/**
 * run_interactive_shell - run interactive part of shell
 * Return: inffinite command
 */

int run_interactive_shell(void)
{
	char *cmd, **av;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 10);
		cmd = get_input();
		if (cmd == NULL)
			return (-1);
		av = tok(cmd, " \n");
		if (av == NULL)
		{
			free(cmd);
			return (-1);
		}
		if (strcompare(av[0], "exit") == 0)
		{
			free(cmd);
			empty1(av);
			break;
		}
		allbuiltin(av, environ);
		if (cmd && cmd[0] != '\n')
			free(cmd);
	}
	return (0);
}

/**
 * run_non_interactive_shell - the function that runs the non-interactive part
 * @inp: user input
 * Return: execute command ones
 */
int run_non_interactive_shell(char *inp)
{
	char **toke;
	size_t g = 0;

	while (getline(&inp, &g, stdin) != -1)
	{
		toke = tok(inp, " \n");
		if (toke == NULL)
		{
			free(inp);
			exit(EXIT_FAILURE);
		}
		if (strcompare(toke[0], "exit") == 0)
		{
			empty1(toke);
			break;
		}
		allbuiltin(toke, environ);
	}
		free(inp);
		return (0);
}
