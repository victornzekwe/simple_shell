#include "main.h"

/**
 * cmd_exe - executes the command
 * @argv: argument vector
 * @lineptr: lineptr
 * @lineptr_new: lineptr new
 * @filename: filename
 * @command: command
 * @loop_count: loop count
 * Return: integer
*/

int cmd_exe(char **argv, char *lineptr,
	char *lineptr_new, char *filename, char *command, int loop_count)
{
	pid_t pid;
	int execve_num;

	if (access(command, F_OK) != -1 && _getenv("PATH1") == NULL)
	{
		pid = fork();
		if (pid == -1)
		{
			perror(filename);
			free(command);
			memory_free(lineptr, lineptr_new, argv);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve_num = execve(command, argv, environ);
			if (execve_num == -1)
			{
				perror(filename);
				memory_free(lineptr, lineptr_new, argv);
			}
			else
				memory_free(lineptr, lineptr_new, argv);
		}
		else
			handle_wait(lineptr, lineptr_new, argv);
	}
	else
		get_path_error(filename, argv, lineptr_new, lineptr, loop_count);
	return (0);
}

/**
 * memory_free - frees memory
 * @lineptr: lineptr
 * @lineptr_new: lineptr new
 * @argv: argument vector
 * Return: integer
*/

int memory_free(char *lineptr, char *lineptr_new, char **argv)
{
	free(argv);
	free(lineptr_new);
	free(lineptr);

	return (0);
}

/**
 * get_path_error - gets path error
 * @filename: filename
 * @argv: argument vector
 * @lineptr_new: lineptr new
 * @lineptr: lineptr
 * @loop_count: loop count
 * Return: integer
*/

int get_path_error(char *filename, char **argv, char *lineptr_new,
	char *lineptr, int loop_count)
{
	_printf("%s: %d: %s: not found\n", filename, loop_count, argv[0]);
	if (isatty(STDIN_FILENO) == 0)
	{
		memory_free(lineptr, lineptr_new, argv);
		exit(127);
	}
	memory_free(lineptr, lineptr_new, argv);
	return (0);
}

/**
 * handle_wait - handle
 * @lineptr: lineptr
 * @lineptr_new: lineptr
 * @argv: argv
 * Return: integer
*/
int handle_wait(char *lineptr, char *lineptr_new, char **argv)
{
	int status = 0;

	wait(&status);
	if (WIFEXITED(status))
		WEXITSTATUS(status);
	if (status != 0 && isatty(STDIN_FILENO) == 0)
	{
		memory_free(lineptr, lineptr_new, argv);
		exit(2);
	}
	else
		memory_free(lineptr, lineptr_new, argv);
	return (0);
}
