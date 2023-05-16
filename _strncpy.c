#include "main.h"

/**
  * _strncpy - does strcpy except that at most n byte of src are copied
  * @dest: buffer destination
  * @src: address of string to copy
  * @n: number of byte of src to copy
  * Return: pointer to the destination string dest
  */

char *_strncpy(char *dest, const char *src, size_t n)
{
	char *start = dest;

	while (n > 0 && *src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
		--n;
	}
	while (n > 0)
	{
		*dest = '\0';
		++dest;
		--n;
	}
	return (start);
}
