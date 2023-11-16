#include "main.h"

/**
 * _strncmp - string n cmp
 * @s1: s1
 * @s2: s2
 * @n: n
 * Return: integer
*/

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 == '\0' || *s2 == '\0')
			break;
		s1++;
		s2++;
	}
	return (0);
}

/**
 * _isspace - space checker
 * @digit: digit
 * Return: digit
*/

int _isspace(int digit)
{
	return (
		digit == ' ' || digit == '\t' ||
		digit == '\v' || digit == '\n' ||
		digit == '\f' || digit == '\r'
	);
}

/**
 * _getenv - gets environment
 * @name: environment name
 * Return: character
*/

char *_getenv(const char *name)
{
	char **env;
	size_t name_length;

	if (name == NULL || name[0] == '\0')
	{
		return (NULL);
	}

	name_length = strlen(name);

	for (env = environ; *env != NULL; ++env)
	{
		if (strncmp(*env, name, name_length) == 0 && (*env)[name_length] == '=')
		{
		return (*env + name_length + 1);
		}
	}

	return (NULL);
}
