#include "main.h"

/**
 * get_path - gets the path of a command
 * @cmd_location: command location
 * @argv: argument vector
 * @lineptr_new: lineptr new
 * @lineptr: lineptr
 * @loop_count: loop count
 * @filename: filename
 * Return: character pointer
*/

int get_path(char **cmd_location, char **argv,
	char *lineptr_new, char *lineptr, char *filename, int loop_count)
{
	char *location = NULL;
	char *location_copy = NULL;
	char *location_token = NULL;
	char *delim = ":";

	location = _getenv("PATH");
	if (location == NULL)
		get_path_error(filename, argv, lineptr_new, lineptr, loop_count);
	location_copy = _strdup(location);
	if (location_copy == NULL)
	{
		exit(EXIT_FAILURE);
	}
	location_token = strtok(location_copy, delim);
	while (location_token != NULL)
	{
		free(*cmd_location);
		*cmd_location = NULL;
		*cmd_location = (char *)malloc(_strlen(location_token)
			+ _strlen(argv[0]) + 2);
		if (*cmd_location == NULL)
		{
			free(location_copy);
			memory_free(lineptr, lineptr_new, argv);
			exit(EXIT_FAILURE);
		}
		_strcpy(*cmd_location, location_token);
		_strcat(*cmd_location, "/");
		_strcat(*cmd_location, argv[0]);
		if (access(*cmd_location, F_OK) == 0)
			break;
		location_token = strtok(NULL, delim);
	}
	free(location_copy);
	return (0);
}
