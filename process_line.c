#include "main.h"

/**
 * process_line - processes line
 * @lineptr: lineptr
 * @argv: argument vector
 * @filename: filename
 * @cmd_location: command location
 * @loop_count: loop count
 * @lineptr_new: lineptr new
 * Return: integer
*/
int process_line(char *lineptr, char **argv,
	char *filename, char *cmd_location, int loop_count, char *lineptr_new)
{
	int count_token = 0;

	if (check_white_space(lineptr) == 1)
	{
		free(lineptr);
		exit(EXIT_SUCCESS);
	}
	lineptr_new = _strdup(lineptr);
	if (lineptr_new == NULL)
	{
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	count_token = tokenize_line(lineptr, lineptr_new, &argv);
	if (count_token > 0)
	{
		if (access(argv[0], F_OK) == 0)
			cmd_exe(argv, lineptr, lineptr_new, filename, argv[0], loop_count);
		else
		{
			get_path(&cmd_location, argv, lineptr_new, lineptr, filename, loop_count);
			cmd_exe(argv, lineptr, lineptr_new, filename, cmd_location, loop_count);
			free(cmd_location);
		}
	}
	return (0);
}

/**
 * check_white_space - checks white space
 * @lineptr: lineptr
 * Return: integer
*/

int check_white_space(const char *lineptr)
{
	while (*lineptr)
	{
		if (!_isspace(*lineptr))
			return (0);
		lineptr++;
	}
	return (1);
}
