#include "main.h"

/**
  * _strchr - returns first occurence of the char c in string s
  * @s: string where c is searched
  * @c: character that is searched
  * Return: a pointer to the matched character, NULL if not found
  */

char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}


/**
 * mystrcat - function concatenates two strings
 *
 * @dest: this is the pointer to the destination string
 * @src: pointer to the source string
 *
 * Return: Pointer to the resulting destination string
 */

char *mystrcat(char *dest, char *src)
{
	int n, i = 0;

	n = strlength(dest);

	while (src[i])
	{
		dest[n + i] = src[i];
		i++;
	}

	dest[n + i] = '\0';

	return (dest);
}

/**
 * alloc - lloc emmory
 * @lineptr: points to prev mem
 * @os: num of byte for previous mem blick
 * @ns: num of bytes to allocate
 * Return: char
 */
char *alloc(char *lineptr, size_t os, size_t ns)
{
	char *p;

	if (ns == 0 && lineptr != NULL)
	{
		return (NULL);
	}
	if (lineptr == NULL)
	{
		lineptr = malloc(ns);
		return (lineptr);
	}
	if (ns == os)
		return (lineptr);
	if (ns > os)
	{
		p = malloc(ns);
		if (p == NULL)
			return (NULL);
		_copy(p, lineptr, os);
	}
	if (ns < os)
	{
		p = malloc(ns);
		if (p == NULL)
			return (NULL);
		_copy(p, lineptr, ns);
	}
	free(lineptr);
	return (p);
}


/**
 * _copy - memory copier.
 *
 * @d: destinatio.
 * @s: source.
 * @g: numof bytes
 *
 * Return: char
 */

char *_copy(char *d, char *s, size_t g)
{
	unsigned int counter;

	if (d == NULL || s == NULL)
		return (NULL);
	for (counter = 0; counter < g; counter++)
	{
		d[counter] = s[counter];
	}

	return (d);
}
