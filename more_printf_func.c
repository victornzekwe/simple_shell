#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _int - integer specifier
* @args: argument list
* @count: argument count
* Return: void
*/

void _int(va_list args, int *count)
{
	_dec(args, count);
}

/**
 * _string - string print function
 * @args: argument list
 * @count: count parameter
*/

void _string(va_list args, int *count)
{
	char *string;
	int i;

	string = va_arg(args, char *);
	if (string == NULL)
		string = "(null)";
	for (i = 0; string[i] != '\0'; i++)
	{
		_putchar(string[i]);
		(*count)++;
	}
}

