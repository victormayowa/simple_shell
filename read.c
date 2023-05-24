#include "main.h"

/**
 * err - to err is human
 * @av: arg vector
 */

void err(char *av)
{
	char *err = ": command not found\n";
	char *sh = "./hsh: ";

	write(2, sh, strlength(sh));
	write(2, av, strlength(av));
	write(2, err, strlength(err));
}

/**
 * gettypro - get line
 * @a: text
 * @b: buf
 * @c: mov pointer.
 * @buf_end: points to the end
 * @g: num of bytes
 * Return: no of char read
 */

ssize_t gettypro(char **a, char *b, char *c, char *buf_end, size_t *g)
{
	ssize_t count = 1, count_tot = 0;
	size_t new;
	char *new_b;

	while (count != 0)
	{
		count = read(STDIN_FILENO, c, 1);
		if (count == -1)
		{
			return (-1);
		}
		count_tot += count;
		if (*c == '\n')
			break;
		if (c == buf_end)
		{
			new = *g * 2;
			new_b = alloc(b, *g, new);
			if (new_b == NULL)
			{
				return (-1);
			}
			b = new_b;
			*a = b;
			c = b + *g - 1;
			buf_end = b + new;
			*g = new;
		}
		c++;
	}
	c++;
	*c = '\0';
	*a = b;
	return (count_tot);
}

/**
 * getty - get stream
 * @ptr: points to stream
 * @g: num of bytes for allocation
 * @str: stream
 * Return:  number of char read
 */

ssize_t getty(char **ptr, size_t *g, FILE *str)
{
	ssize_t count_tot;
	char *buffer, *buf_mov, *buf_end;

	if (!ptr || !g || !str)
	{
		return (-1);
	}
	fflush(stdout);
	if (*ptr == NULL && *g == 0)
	{
		*g = CHARN;
		buffer = malloc(*g);
		if (buffer == NULL)
		{
			return (-1);
		}
		*ptr = buffer;
	}
	else
	{
		buffer = *ptr;
	}
	buf_mov = buffer;
	buf_end = buffer + *g;
	count_tot =  gettypro(ptr, buffer, buf_mov, buf_end, g);
	return (count_tot);
}

/**
 * empty1 - empty memory
 * @av: arg vector
 */
void empty1(char **av)
{
	int counter = 0;

	if (av)
	{
		for (; av[counter]; counter++)
			free(av[counter]);
		free(av);
	}

}

/**
 * empty - empty memory
 * @av: arg vector
 * @env: environment
 */
void empty(char **av, char **env)
{
	int count = 0, line;

	if (av)
	{
		for (; av[count]; count++)
			free(av[count]);
		free(av);
	}
	if (env)
	{
		line = 0;
		for (; env[line]; line++)
			free(env[line]);
		free(env);
	}
}
