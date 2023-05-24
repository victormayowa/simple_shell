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
	while (*current != '\0' && strchr(delimiters, *current) != NULL)
		++current;
	if (*current == '\0')
		return (NULL);
	token = current;
	while (*current != '\0' && strchr(delimiters, *current) == NULL)
		++current;
	if (*current == '\0')
		current = NULL;
	else
		*current++ = '\0';
	return (token);
}

