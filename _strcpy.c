#include "main.h"

/**
  * _strcpy - copies the string pointed to by src, including termination
  * @dest: buffer destination
  * @src: address of string to copy
  * Return: pointer to the destination string dest
  */

char *_strcpy(char *dest, const char *src)
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
