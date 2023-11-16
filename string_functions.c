#include "main.h"

/**
 * _strcat - concatinate
 * @destination: dest
 * @source: source
 * Return: void
*/

char *_strcat(char *destination, const char *source)
{
	char *ptr = destination;

	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*source != '\0')
	{
		*ptr = *source;
		ptr++;
		source++;
	}
	*ptr = '\0';
	return (destination);
}

/**
 * _strchr - string chr
 * @s: s
 * @c: c
 * Return: character
*/

char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/**
 * _strcpy - copy
 * @destination: dest
 * @source: source
 * Return: void
*/

char *_strcpy(char *destination, const char *source)
{
	char *ptr = destination;

	while (*source != '\0')
	{
		*ptr = *source;
		ptr++;
		source++;
	}
	*ptr = '\0';
	return (destination);
}

/**
 * _strdup - duplicates
 * @source: source
 * Return: character
*/

char *_strdup(const char *source)
{
	size_t len;
	char *dup;

	len = _strlen(source) + 1;
	dup = (char *)malloc(len * sizeof(char));
	if (dup != NULL)
		_strcpy(dup, source);
	return (dup);
}

/**
 * _strlen - string length
 * @s: s
 * Return: size_t
*/

size_t _strlen(const char *s)
{
	size_t length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
