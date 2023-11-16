#include "main.h"

/**
 * tokenize_line - tokenizes line
 * @lineptr: lineptr
 * @lineptr_new: lineptr new
 * @argv: argument vector
 * Return: integer
*/

int tokenize_line(char *lineptr, char *lineptr_new, char ***argv)
{
	char *delim = " \n";
	char *str_token;
	int j;
	int count_token = 0;

	count_token = 0;
	str_token = strtok(lineptr, delim);
	while (str_token != NULL)
	{
		str_token = strtok(NULL, delim);
		count_token++;
	}
	count_token++;
	*argv = malloc(sizeof(char *) * count_token);
	if (*argv == NULL)
	{
		free(lineptr);
		free(lineptr_new);
		exit(EXIT_FAILURE);
	}
	else
		str_token = strtok(lineptr_new, delim);
	for (j = 0; str_token != NULL; j++)
	{
		(*argv)[j] = str_token;
		str_token = strtok(NULL, delim);
	}
	(*argv)[j] = NULL;
	return (count_token);
}
