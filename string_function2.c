#include "shell.h"

/**
 * _strlen - Calculate the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
unsigned int _strlen(const char *s)
{
	unsigned int count = 0;

	while (*s)
	{
	count++;
	s++;
	}
	return (count);
}
