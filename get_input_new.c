#include "main.h"

/**
 * get_input -get input from users and reads it
 * Return: the inp
 */

char *get_input(void)
{
	size_t num = 0;
	char *input, *cmd;

	if (getline(&input, &num, stdin) == -1)
	{
		free(input);
		return (NULL);
	}
	if (strcompare(input, "\n") == 0)
	{
		free(input);
		write(STDOUT_FILENO, "#cisfun$ ", 10);
		fflush(stdout);
		return (get_input());
	}
	cmd = strduplicate(input);
	if (input != NULL)
	{
		free(input);
	}
	return (cmd);
}


/**
 * tok - tokenizestr input
 * @cmd: command
 * @d: delimiter
 * Return: tokenized list
 */

char **tok(char *cmd, char *d)
{
	char *cpy, *toke, **av;
	int ac = 0, counter;

	if (cmd == NULL)
	{
		return (NULL);
	}
	cpy = strduplicate(cmd);
	if (cpy == NULL)
	{
		return (NULL);
	}
	toke = _strtok(cmd, d);
	for (; toke; toke = _strtok(NULL, d))
		ac++;
	av = malloc(sizeof(char *) * (ac + 1));
	if (av == NULL)
		return (NULL);
	toke = _strtok(cpy, d);
	counter = 0;
	for (; toke; toke = _strtok(NULL, d), counter++)
		av[counter] = strduplicate(toke);
	av[ac] = NULL;
	free(cpy);
	return (av);
}


/**
 * myenvset - set env
 * @av: arg vector
 * @env: env
 * Return: 0 or 1
 */
int myenvset(char **av, char **env)
{
	int line = 0, counter = 0,  length;
	char *toke, *newcpy, *res = NULL;

	while (av[counter])
		counter++;
	if (counter != 3)
	{
		write(2, ERR, strlength(ERR));
		return (-1);
	}
	length = strlength(av[1]) + strlength(av[2]) + 2;
	while (env[line])
	{
		newcpy = strduplicate(env[line]);
		toke = _strtok(newcpy, "=");
		if (strcompare(toke, av[1]) == 0)
		{
			res = malloc(sizeof(char) * (length + 1));
			if (res == NULL)
				return (-1);
			strcopy(res, toke);
			mystrcat(res, "=");
			mystrcat(res, av[2]);
			env[line] = res;
			free(newcpy);
			return (0);
		}
		free(newcpy);
		line++;
	}
	res = malloc(sizeof(char) * (length + 1));
	if (res == NULL)
		return (-1);
	strcopy(res, av[1]);
	mystrcat(res, "=");
	mystrcat(res, av[2]);
	env[line] = res;
	env[line + 1] = NULL;
	return (1);
}

/**
 * myenvunset - unset environ
 * @av: arg vector
 * @env: environ
 * Return: 0 or 1
 */
int myenvunset(char **av, char **env)
{
	int counter = 0, line = 0, yarn;
	char *toke, *newcpy;

	while (av[counter])
		counter++;
	if (counter != 2)
	{
		write(2, ERR, strlength(ERR));
		return (-1);
	}
	while (env[line])
	{
		newcpy = strduplicate(env[line]);
		toke = _strtok(newcpy, "=");
		if (strcompare(toke, av[1]) == 0)
		{
			yarn = line;
			while (env[yarn + 1])
			{
			env[yarn] = strduplicate(env[yarn + 1]);
			yarn++;
			}
			env[yarn] = NULL;
			free(newcpy);
			return (0);
		}
		free(newcpy);
		line++;
	}
	write(2, VALUE, strlength(VALUE));
	return (-1);
}
