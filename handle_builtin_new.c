#include "main.h"
/**
 * cd_builtin - cd
 * @av: strings vector
 * @env: environ
  */
void cd_builtin(char **av, char **env)
{
	int count = 0;
	char *directory = NULL, input[MAX_INPUT_SIZE];

	while (av[count])
	{
		count++;
	}
	if (count == 1 && av[1] == NULL)
	{
		directory = mygetenv("HOME");
		if (chdir(directory) == -1)
			perror(av[0]);
	mypwd(env, directory);
	}
	else if (strcompare(av[1], "-") == 0 && count == 2)
	{
		directory = mygetenv("OLDPWD");
		if (chdir(directory) == -1)
			perror(av[0]);
		else
			mypwd(env, directory);
	}
	else if (count == 2)
	{
		if (chdir(av[1]) == -1)
			perror(av[1]);
		else
		{
			getcwd(input, MAX_INPUT_SIZE);
			mypwd(env, directory);
		}
	}
	else
	{
		write(2, ERR, strlength(ERR));
		exit(EXIT_FAILURE);
	}
}

/**
 * allbuiltin - choose between builtins
 * @av: argument vector
 * @env: environment
 * Return: 1
 */
int allbuiltin(char **av, char **env)
{

	if (strcompare(av[0], "setenv") == 0)
	{
		myenvset(av, env);
		 empty1(av);
	}
	else if (strcompare(av[0], "unsetenv") == 0)
	{
		myenvunset(av, env);
		 empty1(av);
	}
	else if (strcompare(av[0], "cd") == 0)
	{
		cd_builtin(av, env);
		empty1(av);
	}
	else if (strcompare(av[0], "env") == 0)
	{
		myenv();
		empty1(av);
	}
	else
	{
		execute_cmd(av);
	}
	return (1);
}

/**
 * myenv - my environment
 */
void myenv(void)
{
	int counter = 0;

	for (; environ[counter] != NULL; counter++)
	{
		_puts(environ[counter]);
	}
}

/**
  * exec_new -  executes new
  * @av: array vector
  * Return: 1
 */
char *exec_new(char **av)
{
	int i;
	char *pathfinder, *tok = NULL, *file = NULL;
	struct stat status;

	if (stat(av[0], &status) == 0)
	{
		file = strduplicate(av[0]);
		return (file);
	}
	pathfinder = mygetenv("PATH");
	if (pathfinder == NULL)
		return (NULL);
	tok = _strtok(pathfinder, ":");
	while (tok != NULL)
	{
		i = strlength(av[0]) + strlength(tok) + 2;
		file = malloc(sizeof(char) * i);
		if (file == NULL)
			return (NULL);
		strcopy(file, tok);
		mystrcat(file, "/");
		mystrcat(file, av[0]);
		if (stat(file, &status) == 0)
		{
			free(pathfinder);
			return (file);
		}
		free(file);
		tok = _strtok(NULL, ":");
	}
	free(pathfinder);
	return (NULL);
}
/**
 * execute_cmd - cmd execution
 * @av: argukment vector
 */
void execute_cmd(char **av)
{
	pid_t pid;
	int i, stat;
	char *p;

	p = exec_new(av);
	if (p == NULL)
		perror("./hsh");
	else
	{
		pid = fork();
		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			i = execve(p, av, environ);
			if (i == -1)
			{
				empty1(av);
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		else if (pid > 0)
			wait(&stat);
		if (p != NULL)
			free(p);
		}
		empty1(av);
}
