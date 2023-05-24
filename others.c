#include <stdbool.h>
#include "main.h"
/**
 * _strtok - replicates strtok function
 * @str: string
 * @delimiters: delimiter
 * Return: token
 */

char *_strtok(char *str, const char *delimiters)
{
	static char *current;
	char *token;

	if (str != NULL)
		current = str;
	if (current == NULL || *current == '\0')
		return (NULL);
	while (*current != '\0' && _strchr(delimiters, *current) != NULL)
		++current;
	if (*current == '\0')
		return (NULL);
	token = current;
	while (*current != '\0' && _strchr(delimiters, *current) == NULL)
		++current;
	if (*current == '\0')
		current = NULL;
	else
		*current++ = '\0';
	return (token);
}


/**
 * strcompare - compare two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: an integer greater than, equal to, or less than 0, depending
 * on the lexicographical order of the two strings
 */

int strcompare(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

#include "main.h"

/**
 * strlength - Returns the length of a string
 * @str: The string to get the length of
 *
 * Return: The length of the string
 */
size_t strlength(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}


/**
  * strduplicate - duplicates the inside another string variable address
  * @s: pointer to the address of the variable where string is copied into
  * Return: pointer
  */

char *strduplicate(const char *s)
{
	size_t len = strlength(s) + 1;
	char *p = malloc(len);

	if (p)
		strcopy(p, s);
	return (p);
}

/**
  * strcopy - copies the string pointed to by src, including termination
  *
  * @dest: buffer destination
  * @src: address of string to copy
  * Return: pointer to the destination string dest
  */

char *strcopy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
