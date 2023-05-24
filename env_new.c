#include "main.h"

/**
 * mygetenv - extract the environment needed
 * @n: name of variable
 * Return: char
 */

char *mygetenv(const char *n)
{
	char **env = createnv();
	int counter = 0;
	char *toke, *newcpy, *tokenize, *variable = NULL;

	if (env == NULL)
		return (NULL);
	while (env[counter])
	{
		newcpy = strduplicate(env[counter]);
		toke = _strtok(newcpy, "=");
		if (strcompare(toke, n) == 0)
		{
			tokenize = _strtok(NULL, "=");
			variable = strduplicate(tokenize);
			empty1(env);
			free(newcpy);
			return (variable);
		}
		counter++;
		free(newcpy);
	}
	free(variable);
	empty1(env);
	return (NULL);
}
/**
 * createnv - create new env
 * Return: env
 */

char **createnv(void)
{
	char **env1;
	int counter = 0, line = 0;

	while (environ[counter])
	{
		counter++;
	}
	env1 = malloc(sizeof(char *) * (counter + 1));
	if (env1 == NULL)
		return (NULL);
	for (line = 0; line < counter; line++)
		env1[line] = strduplicate(environ[line]);
	env1[line] = NULL;
	return (env1);
}


/**
 * myvarset - my value sets
 * @av: arg vector
 * @env: environ variable
 * @val: variable
 * Return: 0 or 1
 */

int myvarset(char *av, char *val, char **env)
{
	int line = 0;

	char *newcpy, *toke, *res;

	while (env[line])
	{
		newcpy = strduplicate(env[line]);
		toke = _strtok(newcpy, "=");
		if (strcompare(toke, av) == 0)
		{
			res = malloc(sizeof(char) * (strlength(av) + strlength(val) + 3));
			if (res == NULL)
				return (-1);
			strcopy(res, toke);
			mystrcat(res, "=");
			mystrcat(res, val);
			env[line] = res;
			free(newcpy);
			return (0);
		}
		free(newcpy);
		line++;
	}
	return (-1);
}

/**
 * mypwd - present working direcctory
 * @env: environ
 * @cur: directory
 * Return: 0 or 1
 */

int mypwd(char **env, char *cur)
{
	char *o;

	o = mygetenv("PWD");
	if (o == NULL)
		return (-1);
	if (myvarset("PWD", cur, env) == -1 || myvarset("OLDPWD", o, env) == -1)
		return (-1);
	return (0);
}
