#include "main.h"

/**
 * _strncmp - compare two strings up to a given number of characters
 * @s1: first string
 * @s2: second string
 * @n: maximum number of characters to compare
 *
 * Return: an integer less than, equal to, or greater than zero if s1 is
 * found, respectively, to be less than, to match, or be greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s1 == *s2)
	{
		++s1;
		++s2;
		--n;
	}
	return (n == 0 ? 0 : *s1 - *s2);
}
