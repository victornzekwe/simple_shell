#include "main.h"

/**
 * get_line - getline
 * @filename: filename
 * Return: interger
*/

int get_line(char *filename)
{
	char *prompt = "$ ";
	int loop_count = 0;

	while (1)
	{
		char *lineptr = NULL;
		char **argv = NULL;
		char *cmd_location = NULL;
		char *lineptr_new = NULL;
		size_t buff_size = 0;
		ssize_t num_read = 0;

		loop_count++;
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, prompt, 3);
		num_read = getline(&lineptr, &buff_size, stdin);
		if (num_read == -1 || num_read == 0)
			check_getline(lineptr, buff_size, lineptr_new, argv);
		if (num_read == 0)
		{ free(lineptr);
			exit(EXIT_SUCCESS);
		}
		else if (num_read == 1 && lineptr[0] == '\n')
		{ free(lineptr);
			continue;
		}
		else if (_strncmp(lineptr, "exit", 4) == 0)
		{ memory_free(lineptr, lineptr_new, argv);
			exit(EXIT_SUCCESS);
		}
		else if (num_read == 4 && _strncmp(lineptr, "env", 4) == 0)
		{ print_environ();
			free(lineptr);
		}
		else
			process_line(lineptr, argv, filename, cmd_location,
				loop_count, lineptr_new);
	}
	return (0);
}

/**
 * check_getline - checks getline
 * @lineptr: lineptr
 * @buff_size: buffer size
 * @lineptr_new: lineptr new
 * @argv: argument vector
 * Return: integer
*/

int check_getline(char *lineptr, size_t buff_size,
	char *lineptr_new, char **argv)
{
	if (lineptr == NULL || buff_size == 0)
	{
		memory_free(lineptr, lineptr_new, argv);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		memory_free(lineptr, lineptr_new, argv);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

/**
 * print_environ - prints environment
 * Return: integer
*/

int print_environ(void)
{
	char **ptr = environ;
	char *env = NULL;
	int len = 0;

	while (*ptr != NULL)
	{
		env = *ptr;
		len = _strlen(env);
		write(1, env, len);
		write(1, "\n", 1);
		ptr++;
	}
	return (0);
}
