#include "shell.h"

/**
 * _strdup - Duplicate a string
 * @str: string to duplicate
 *
 * Return: A pointer to duplicated string, or NULL if it fails
 */
char *_strdup(const char *str)
{
	char *new_str;
	size_t len = 0, i;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
	{
		len++;
	}
	new_str = (char *)malloc((len + 1) * sizeof(char));

	if (new_str == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		new_str[i] = str[i];

	return (new_str);
}

/**
 * _strcmp - Compares the two strings.
 * @str1: first string to compare.
 * @str2: econd string to compare.
 *
 * Return: An integer .
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * _strncmp - Compares two strings up to a specified length
 * @str1: The first string to compare
 * @str2: econd string to compare
 * @n:    maximum number of characters to compare
 *
 * Return: An integer.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * _strcat - Concatenate two strings
 * @dest: destination og the string
 * @src:  source string to concatenate
 *
 * Return: A pointer to the concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	char *original_dest;

	original_dest = dest;

	while (*dest)
		dest++;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}

/**
 * _strcpy - Copy a string.
 * @destination: The destination string.
 * @source:      The source string to copy.
 *
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *destination, const char *source)
{
	char *ptr;

	if (destination == NULL)
		return (NULL);

	ptr = destination;
	while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return (ptr);
}

